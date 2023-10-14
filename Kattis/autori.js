'use strict';

const fs = require("fs");
const isLocal = true;
const readStream = (isLocal) ? fs.createReadStream("./io/input.in", "UTF-8") : process.stdin;
readStream.resume();
readStream.setEncoding('utf-8');
let inputString = '';
let currentLine = 0;

readStream.on('data', inputStdin => {
    inputString += inputStdin;

});

readStream.on('end', function() {
    inputString = inputString.replace(/\s*$/, '')
        .split('\n')
        .map(str => str.replace(/\s*$/, ''));
    main();
});

function readLine() {
    return inputString[currentLine++];
}
function main() {
    const input = readLine().split('-')
    input.forEach((el) => process.stdout.write(el[0]))

}
