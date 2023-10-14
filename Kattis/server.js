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
    let [n, t] = readLine().split(' ').map(el => parseInt(el))
    const arr = readLine().split(' ').map(el => parseInt(el))
    let ans = 0
    let exit = false
    while(arr.length && !exit) {
      const curr = arr.shift()
      if (t - curr >= 0) {
        ans += 1
        t -= curr
      } else {
        exit = true
        break
      }
    }
    console.log(ans)
}
