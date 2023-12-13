'use strict';

const fs = require("fs");
const isLocal = true;
const readStream = (isLocal) ? fs.createReadStream("../.././io/input.in", "UTF-8") : process.stdin;
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
    let line = "";
    let ret = 0;
    let dp = new Map();
    while(line = readLine()) {
      line = line.split(' ');
      let springs = line[0];
      const contigious = line[1].split(',').map(el => parseInt(el));
      // console.log("LINE");
      const accumulate = (a, b) => a + b;
      const solve = (row, ns) => {
        row = row.replace(/^\.+|\.+$/, '');
        // console.log(row, ns)
        if (row === '') return ns.length ? 0 : 1;
        if (!ns.length) return row.includes('#') ? 0 : 1;
        const key = [row, ns].join(' ');
        if (dp.has(key)) return dp.get(key);

        let result = 0;
        const damaged = row.match(/^#+(?=\.|$)/);
        if (damaged) {
            if (damaged[0].length === ns[0]) {
                result += solve(row.slice(ns[0]), ns.slice(1));
            }
        } else if (row.includes('?')) {
            const total = ns.reduce(accumulate);
            result += solve(row.replace('?', '.'), ns);
            if ((row.match(/#/g) || []).length < total) {
                result += solve(row.replace('?', '#'), ns);
            }
        }
        dp.set(key, result);
        return result;
      };
      ret += solve(springs, contigious);
    }
    console.log(ret);
}

