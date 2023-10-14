'use strict';

const fs = require("fs");
const isLocal = false;
const readStream = (isLocal) ? fs.createReadStream("../io/input.in", "UTF-8") : process.stdin;
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
    const [l, r] = readLine().split(' ');
    const n = parseInt([...l].reverse().join(''));
    const m = parseInt([...r].reverse().join(''));
    console.log(Math.max(n, m))

}
