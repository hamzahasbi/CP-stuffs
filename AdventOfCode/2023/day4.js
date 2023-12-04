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
    let rows = [];
    let mp = new Map();
    let cardC = new Map();
    let index = 0;
    while(line = readLine()) {
      mp.clear();
      const lineargs = line.split(':');
      const card = lineargs[1].split('|');
      const wining = card[0].split(' ').filter(Number).forEach(el => {
        mp.set(parseInt(el), true);
      });
      // console.log(wining)

      let ans = 0;
      const mine = card[1].split(' ').filter(Number).forEach(el => {
        if (mp.has(parseInt(el))) {
          // console.log(el)
          ans += 1;
        }
      });
      // Part 1 answer was the sum of (1 << (ans - 1)) or 2 ^ (ans - 1)
      rows.push(ans);
      cardC.set(index, 1);
      index += 1;
    }
    ret = 0;
    mp.clear();

    rows.forEach((val, idx) => {

      let curr = cardC.get(idx);
      while(curr > 0) {
        let runVal = val;
        let j = idx + 1;
        while(runVal > 0 && j < rows.length) {
          const update = cardC.get(j) + 1;
          cardC.set(j, update);
          j += 1;
          runVal -= 1;
        }
        curr -= 1;
      }
    })
    cardC.forEach((val, key) => {
      ret += val;
    })
    console.log(ret)
}
