import {Project, ClassDeclaration, Scope, ConstructorDeclarationStructure, ts, createWrappedNode, MethodDeclarationStructure, MethodDeclaration, Statement} from "ts-morph";
import CodeBlockWriter from "code-block-writer";

const NGX_TRANSLATE = 'ngx-translate';
let NGX_TRANSLATE_IMPORT_NAME = 'translate';
let TRANSLATE_VALUE = '_i18Values';
let TRANSLATE_NAME = '_translate';

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
  dealTranslateI18nMethod(component);
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
  // TO DO ---- more than one constructor
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

function dealTranslateI18nMethod(component: ClassDeclaration) {
  let translateI18nMethod = component.getMethods().find(method => method.getName() === 'translateI18n');
  if (translateI18nMethod) {
    console.log('translateI18n function exited');
    addNewTranslateStrings(['c'], translateI18nMethod)
  } else {
    translateI18nMethod = component.addMethod({
      'name': 'translateI18n',
      scope: Scope.Private
    });
    translateI18nMethod.setBodyText(writeTranslateMethodText(['a', 'b']));
  }
}

function writeTranslateMethodText(translateStrings: string[]): string {
    writer.writeLine(`this.${TRANSLATE_NAME}.get([`);
    for (let translateString of translateStrings) {
      writer.writeLine(`'${translateString}',`);
    }
    writer.writeLine(`]).subscribe((result: any) => this.${TRANSLATE_VALUE} = result);`);
    return writer.toString()
}

function addNewTranslateStrings(translateStrings: string[], translateI18nMethod: MethodDeclaration) {
  translateI18nMethod.compilerNode.forEachChild((node) => {
    return node;
  })
  translateI18nMethod.getStatement((statement: Statement) => {
    statement.compilerNode;
    return true;
  })
}

function initSetting() {
  NGX_TRANSLATE_IMPORT_NAME = 'translate';
  TRANSLATE_VALUE = '_i18Values';
  TRANSLATE_NAME = '_translate';
}

project.save().then(() => console.log("Saved!"))
