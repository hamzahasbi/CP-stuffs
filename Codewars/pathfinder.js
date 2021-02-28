const isValid = (i, j, N) => {
  return i >= 0 && j >= 0 && i < N && j < N;
};

const newMaze = (maze, N) => {
  let Mmaze = [];
  let j = 0;

  for (let i = 0; i <= N - 1; i++) {
    let row = [];
    let count = 0;
    while (j < maze.length && count <= N - 1) {
      if (maze[j] !== "\n") {
        row.push(maze[j]);
        count++;
      }
      j++;
    }
    Mmaze.push(row);
  }
  return Mmaze;
};
function pathFinder(maze) {
  let visited = new Map();
  const N = maze.split("\n").length;
  const Maze = newMaze(maze, N);
  let bfs = [];
  bfs.push([0, 0]);

  visited.set("0i0j", 0);
  while (bfs.length > 0) {
    let vertex = bfs.shift();
    for (let dx = -1; dx <= 1; dx++) {
      for (let dy = -1; dy <= 1; dy++) {
        if (Math.abs(dx) === Math.abs(dy)) continue;
        let newx = dx + vertex[0];
        let newy = dy + vertex[1];

        if (visited.has(newx + "i" + newy + "j") || !isValid(newx, newy, N))
          continue;
        if (Maze[newx][newy] === ".") {
          bfs.push([newx, newy]);
          const parent = visited.get(vertex[0] + "i" + vertex[1] + "j");
          visited.set(newx + "i" + newy + "j", parent + 1);
        }
      }
    }
  }
  const bound = N - 1;
  return visited.get(bound + "i" + bound + "j") !== undefined
    ? visited.get(bound + "i" + bound + "j")
    : false;
}

function testMaze(expected, maze) {
    let actual = pathFinder(maze);
    console.log(actual, expected);
}
testMaze(
  16,
  `.W.WWW.WW
.........
.........
.W..W..W.
....W.W..
...W.W...
...W.....
WWW....W.
....W..W.`
);

