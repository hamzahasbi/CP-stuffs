'use strict';

const fs = require("fs");
const isLocal = true;
const readStream = (isLocal) ? fs.createReadStream("../../io/input.in", "UTF-8") : process.stdin;
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
    let fineAns = 0;
    while(line = readLine()) {
      let infos = line.split(" ").map(el => parseInt(el));
      let last = 0;
      let finish = false;
      let lineAns = [];
      lineAns.push(infos)
      while(!finish) {
        let enhanced = [];
        let start = false;
        infos.forEach(el => {
          if (start) {
            enhanced.push(el - last);
          }
          start = true;
          last = el;
        })
        finish = true;
        enhanced.forEach(el => {
          if (el != 0) {
            finish = false;
          }
        })
        infos = enhanced;
        lineAns.push(enhanced);
      }
      // Part 1
      // for(let i = lineAns.length - 1; i >= 0; --i) {
      //   fineAns += lineAns[i].pop();
      // }

      // Part 2
      let ans = 0;
      for(let i = lineAns.length - 2; i >= 0; --i) {
        // console.log(lineAns[i].pop());
        ans = lineAns[i][0] - ans;
      }
      fineAns += ans;

    }
    console.log(fineAns);


}

