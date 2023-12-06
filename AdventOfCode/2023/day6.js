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
    let time = [];
    let dis = [];
    let mp = new Map();
    let index = 0;
    while(line = readLine()) {
      mp.clear();
      const lineargs = line.split(':');
      if (time.length > 0) {
        dis = lineargs[1].split(' ').filter((el) => !isNaN(parseInt(el))).join('');
      }
      else {
        time = lineargs[1].split(' ').filter((el) => !isNaN(parseInt(el))).join('');
      }

    }
    dis = parseInt(dis);
    time = parseInt(time);

    // console.log(time, dis)
    ret = 0;
// Part 2
    for( let n = 0; n <= time; n++ ){
      if( ( ( time - n ) * n ) > dis ){
          ret++;
      }
    }
  // Part 1
    // for(index = 0; index < time.length; index += 1) {
    //   let timer = 0;
    //   for(let j = 0; j <= time[index]; ++j) {
    //     const left = time[index] - j;
    //     const speed = j;
    //     const distance = speed * left;
    //     if (distance > dis[index]) {
    //       timer += 1;
    //       if (ret == 0) ret = 1; /* to handle the cumul */
    //     }
    //   }
    //   ret *= timer;
    // }
    console.log(ret)
}

