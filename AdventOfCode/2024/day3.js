'use strict';

const isLocal = true;
const file = Bun.file("../../io/input.in");
let inputString = '';
let currentLine = 0;

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
    let input = "";
    let line = "";

    while(line = readLine()) {
      input += line;
    }
    line = input;
    let ans = 0;
      // Part 1.
/*       const regex = /mul\((\d+),(\d+)\)/g;
      const matches = [...line.matchAll(regex)];
      for (const match of matches) {
        const [fullMatch, num1, num2] = match;
        ans += parseInt(num1) * parseInt(num2);
        // console.log(`Found multiplication: ${num1} * ${num2}`);
      } */

        // Part 2.
    const regex = /mul\((\d+),(\d+)\)/g;
    const matches = [...line.matchAll(regex)];
    const doRegex = /do\(\)/g;  // Regex to match "do()"
    const treat = [...line.matchAll(doRegex)].map(el => el.index);
    const dontRegex = /don't\(\)/g;  // Regex to match "don't()"
    const move = [...line.matchAll(dontRegex)].map(el => el.index);
    // console.log(treat, move);

    const find = (p, search) => {
      let left = 0, right = p.length - 1;
      let prevMove = -1;
      while (left <= right) {
        const mid = Math.floor((left + right) / 2);
        if (p[mid] <= search) {
            prevMove = p[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
      }
      return prevMove;
    }
    for (const match of matches) {
      const [fullMatch, num1, num2] = match;
      const skip = match.index;
      // Find largest element smaller than skip using binary search

      let can = find(treat, skip);
      let cant = find(move, skip);
      console.log(skip, can, cant);
      if (can > cant || cant == -1) {
        ans += parseInt(num1) * parseInt(num2);
      }
      // console.log(`Found multiplication: ${num1} * ${num2}`);
    }
    console.log(ans);
}

async function init() {
  inputString = await file.text();
  inputString = inputString.replace(/\s*$/, '')
      .split('\n')
      .map(str => str.replace(/\s*$/, ''));
  main();
}

init();
