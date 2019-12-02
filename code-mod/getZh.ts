import * as ts from 'typescript';
import {sync as glob} from 'glob';
import * as path from 'path';
import * as fs from 'fs';
import {getZhFromTs} from './ast-util';
import {StringList} from './types';
const translateJson: StringList = {};

const sourceDir = path.join(__dirname, './src');

function getAllZhString(codeDir: string) {
    console.log(`==> start get zh`);
    glob('**/*.ts', {cwd: codeDir}).forEach(fileName => {
    const filePath = path.join(codeDir, fileName);
    let code = fs.readFileSync(filePath).toString();
    ts.transpileModule(code, {
    compilerOptions: {module: ts.ModuleKind.ESNext},
    transformers: {before: [getZhFromTs(filePath, translateJson)]}
           });
       });
}

getAllZhString(sourceDir);

const zhStrings = new Set<string>();
for (let key in translateJson) {
    translateJson[key].forEach( zhString => zhStrings.add(zhString));
}
let output: any = [];
let key = 'key', i = 0;
for (let zhString of zhStrings) {
    output.push({
        key: `${key}${i++}`,
        zh: zhString,
        en: ''
    })
}

fs.writeFileSync(path.join(__dirname, 'translate.json'), JSON.stringify(output, null, '\t'));