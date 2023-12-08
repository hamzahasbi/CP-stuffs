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


function gcd(a, b) {
  for (let temp = b; b !== 0;) {
      b = a % b;
      a = temp;
      temp = b;
  }
  return a;
}

function lcm(a, b) {
  const gcdValue = gcd(a, b);
  return (a * b) / gcdValue;
}

function readLine() {
    return inputString[currentLine++];
}
function main() {
    let line = "";
    const path = readLine();
    let g = new Map();
    let sz = path.length - 1;
    let roots = []
    let leafs = []
    readLine();
    while(line = readLine()) {
      const infos = line.split("=");
      if (infos.length) {
        const from = infos[0].trim();
        const to = infos[1].trim().replace(/[{()}[\]]/g, '').split(",").map((el) => el.trim());
        g.set(from, to);

      }
    }
    g.forEach((val, key) => {
      if (key.endsWith('A')) roots.push(key);
      if (key.endsWith('Z')) leafs.push(key);
    })
    // console.log(g);
    const dfs = (node, dir) => {
      if (node.endsWith('Z')) {
        return 0;
      }
      // console.log(node);
      const go = path[dir] === 'L' ? 0 : 1;
      const next = dir === sz ? 0 : dir +  1;
      return 1 + dfs(g.get(node)[go], next);
    }

    let ans = 1;
    roots.forEach((root) => {
      const curr = dfs(root, 0);
      ans = lcm(curr, ans);
    })

    console.log(ans);
}

