'use strict';

const fs = require("fs");
const isLocal = true;
const readStream = process.stdin;
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
    readLine();
    const skip = ['a', 'e', 'i', 'o', 'u']
    const input = readLine().split(' ')

    input.forEach((el) =>{
      let ans = el[0]
      let last = el[0]
      for(let i = 1; i < el.length; i += 1) {
        if (last != el[i]) {
          ans += el[i]
          last = el[i]
        }
      }
      ans += last != el[el.length - 1] ? el[el.length - 1] : ""
      process.stdout.write(ans.length > 1 ? ans[0] : "")
      for(let i = 1; i < ans.length - 1; i += 1) {
        if (!skip.includes(ans[i])) {
          process.stdout.write(ans[i])
        }
      }

      process.stdout.write(ans[ans.length - 1 ] + " ")
    })

}
