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


    const line = readLine();
    const susbset = line.split(';');

    let ans = 0;
    susbset.forEach((el) => {
      if (el.includes('-')) {
        const sub = el.split('-');
        ans += parseInt(sub[1]) - parseInt(sub[0]) + 1;
      } else ans += 1;
    })
    console.log(ans)

}
