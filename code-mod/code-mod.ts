import {Project, ClassDeclaration, Scope, ConstructorDeclarationStructure, ts, createWrappedNode, MethodDeclarationStructure, MethodDeclaration, Statement, ArrayLiteralExpression} from "ts-morph";
import CodeBlockWriter from "code-block-writer";
import * as fs from "fs";
import { zhMatchReg } from './ast-util';
import {TranslateValue} from './types';

const NGX_TRANSLATE = 'ngx-translate';
let NGX_TRANSLATE_IMPORT_NAME = 'translate';
let TRANSLATE_VALUE = '_i18Values';
let TRANSLATE_NAME = '_translate';
let TRANSLATE_FUNCTION_NAME = '_getTranslate'
let translateJson: TranslateValue[];

try {
    translateJson = JSON.parse(fs.readFileSync('translate.json').toString())
} catch(error) {
    console.log('translate.json not found');
    process.exit(1);
}


const filePath = "src/**/*.ts";
const project = new Project({});
project.addSourceFilesAtPaths(filePath);

const source = project.getSourceFileOrThrow("src/source.ts");
const writer = new CodeBlockWriter();

// deal class
const componentClasses = source.getClasses().filter((tsclass) => {
    const tsclassDecorators = tsclass.getStructure().decorators;
    // must be an angular component class
    if (tsclassDecorators) {
        if (tsclassDecorators.map(decorator => decorator.name).indexOf('Component') > -1) {
            return true
        }
    }
    return false
});

componentClasses.forEach(component => translateComponent(component));

// deal import
const translateImport = source.getImportDeclaration(NGX_TRANSLATE);
if (translateImport) {
    NGX_TRANSLATE_IMPORT_NAME = translateImport.getNamedImports()[0].getName();
} else {
    source.addImportDeclaration({
        namedImports: [NGX_TRANSLATE_IMPORT_NAME],
        moduleSpecifier: NGX_TRANSLATE
    });
}

function translateComponent(component: ClassDeclaration) {
  dealProperty(component);
  dealInjectDependency(component);
  dealTranslateI18nMethod(component, translateJson.map(value => value.key));
  dealZhStringLiteral(component);
}

function dealProperty(component: ClassDeclaration) {
  if (component.getProperties().find(property => property.getName() === TRANSLATE_VALUE)) {
    console.log('_i18Values property exited');
  } else {
    component.addProperty({
      name: TRANSLATE_VALUE,
      scope: Scope.Private
    });
  }
}

function dealInjectDependency(component: ClassDeclaration) {
  // TO DO ---- multiple constructor or no constructor
    const componentConstructor = component.getConstructors()[0];
    const componentConstructorStructure = componentConstructor.getStructure();
    if (componentConstructorStructure.parameters) {
        const translateParameter =  componentConstructorStructure.parameters.find(parameter => parameter.type === NGX_TRANSLATE_IMPORT_NAME);
        if (translateParameter) {
            TRANSLATE_NAME = translateParameter.name;
        } else {
            componentConstructorStructure.parameters.push({
                name: TRANSLATE_NAME,
                type: NGX_TRANSLATE_IMPORT_NAME,
                scope: Scope.Private
            });
        }
    }
    componentConstructor.set(componentConstructorStructure as ConstructorDeclarationStructure);
}

function dealTranslateI18nMethod(component: ClassDeclaration, translateStrings: string[]) {
  let translateI18nMethod = component.getMethods().find(method => method.getName() === TRANSLATE_FUNCTION_NAME);
  let array = new Set<string>();
  if (translateI18nMethod) {
    console.log('getTranslate function exited');
    array = findOldTranslateStrings(translateI18nMethod);
    for (let translateString of translateStrings) {
        array.add(translateString);
    }
    translateStrings = Array.from(array);
  } else {
    translateI18nMethod = component.addMethod({
      'name': TRANSLATE_FUNCTION_NAME,
      scope: Scope.Private
    });
  }
  translateI18nMethod.setBodyText(translateMethodTextFactory(translateStrings));
}

function translateMethodTextFactory(translateStrings: string[]): string {
    writer.writeLine(`this.${TRANSLATE_NAME}.get([`);
    for (let translateString of translateStrings) {
      writer.writeLine(`'${translateString}',`);
    }
    writer.writeLine(`]).subscribe((result: any) => this.${TRANSLATE_VALUE} = result);`);
    return writer.toString()
}

function findOldTranslateStrings(translateI18nMethod: MethodDeclaration): Set<string> {
    const array = new Set<string>();
    translateI18nMethod.transform(traversal => {
        let node = traversal.visitChildren();

        if (ts.isCallExpression(node) && ts.isPropertyAccessExpression(node.getChildAt(0))) {
            const temp = node.getChildAt(0);
            if (ts.isPropertyAccessExpression(temp.getChildAt(0))) {
                if (ts.isIdentifier(temp.getChildAt(2)) && 
                    temp.getChildAt(2).getText() === 'get' &&
                    ts.isIdentifier(temp.getChildAt(0).getChildAt(2)) &&
                    temp.getChildAt(0).getChildAt(2).getText() === TRANSLATE_NAME) {
                        const translateArray = node.getChildAt(2).getChildAt(0);
                        if (ts.isArrayLiteralExpression(translateArray)) {
                            translateArray.getChildAt(1).getChildren().forEach(value => {
                                if (ts.isStringLiteral(value)) {
                                    array.add(value.text)
                                }
                            });
                        }
                }
            }
        }
        return node;
    });
    return array;
}

function dealZhStringLiteral(component: ClassDeclaration) {
    component.transform(traversal => {
        let node = traversal.visitChildren();
        if (ts.isStringLiteral(node) && node.getText().match(zhMatchReg)) {
            const text = node.text;
            const temp = translateJson.find(value => text === value.zh);
            if (temp) {
                return ts.createElementAccess(
                    ts.createPropertyAccess(
                      ts.createThis(),
                      ts.createIdentifier(TRANSLATE_VALUE)
                    ),
                    ts.createStringLiteral(temp.key)
                  );
            }
        }
        return node;
    })
}

function initSetting() {
  NGX_TRANSLATE_IMPORT_NAME = 'translate';
  TRANSLATE_VALUE = '_i18Values';
  TRANSLATE_NAME = '_translate';
}

project.save().then(() => console.log("Saved!"))