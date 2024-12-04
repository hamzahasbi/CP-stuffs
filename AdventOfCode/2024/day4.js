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

// Part 1.
function findXMAS(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const directions = [
        [-1, -1], [-1, 0], [-1, 1],  // diagonal up, up, diagonal up
        [0, -1],           [0, 1],    // left, right
        [1, -1],  [1, 0],  [1, 1]     // diagonal down, down, diagonal down
    ];
    let count = 0;

    function checkDirection(row, col, dir) {
        const word = "XMAS";
        for(let i = 0; i < word.length; i++) {
            const newRow = row + (dir[0] * i);
            const newCol = col + (dir[1] * i);
            if(newRow < 0 || newRow >= rows ||
               newCol < 0 || newCol >= cols ||
               grid[newRow][newCol] !== word[i]) {
                return false;
            }
        }
        return true;
    }

    for(let row = 0; row < rows; row++) {
        for(let col = 0; col < cols; col++) {
            if(grid[row][col] === 'X') {
                for(const dir of directions) {
                    if(checkDirection(row, col, dir)) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

// Part 2.
// Part 2.
function findXMAS2(grid) {
  const rows = grid.length;
  const cols = grid[0].length;
  let count = 0;

  function checkXPattern(row, col) {
      if (row + 2 >= rows || col + 2 >= cols) return false;

      // Check all possible combinations of MAS and SAM
      const patterns = [
          // Original MAS-MAS pattern
          {
              tl: ['M','A','S'],  // top-left to bottom-right
              tr: ['M','A','S']   // top-right to bottom-left
          },
          // SAM-MAS pattern
          {
              tl: ['S','A','M'],
              tr: ['M','A','S']
          },
          // MAS-SAM pattern
          {
              tl: ['M','A','S'],
              tr: ['S','A','M']
          },
          // SAM-SAM pattern
          {
              tl: ['S','A','M'],
              tr: ['S','A','M']
          }
      ];

      for (const pattern of patterns) {
          if (
              // Check top-left to bottom-right diagonal
              grid[row][col] === pattern.tl[0] &&
              grid[row+1][col+1] === pattern.tl[1] &&
              grid[row+2][col+2] === pattern.tl[2] &&
              // Check top-right to bottom-left diagonal
              grid[row][col+2] === pattern.tr[0] &&
              grid[row+1][col+1] === pattern.tr[1] &&
              grid[row+2][col] === pattern.tr[2]
          ) {
              return true;
          }
      }

      return false;
  }

  for(let row = 0; row < rows; row++) {
      for(let col = 0; col < cols; col++) {
          if(checkXPattern(row, col)) {
              count++;
          }
      }
  }

  return count;
}
function main() {
    let grid = [];
    let line = "";
    while(line = readLine()) {
        grid.push(line.split(''));
    }
    // console.log(findXMAS(grid));
    console.log(findXMAS2(grid));
}


async function init() {
  inputString = await file.text();
  inputString = inputString.replace(/\s*$/, '')
      .split('\n')
      .map(str => str.replace(/\s*$/, ''));
  main();
}

init();
