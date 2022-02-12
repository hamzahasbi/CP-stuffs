'use strict';

const fs = require("fs"); 
const isLocal = false;
const readStream = (isLocal) ? fs.createReadStream("./IO/Input.in", "UTF-8") : process.stdin; 
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


    const n = parseInt(readLine(), 10);
    let data = new Map();

    for(let i = 0; i < n; ++i) {
        const name = readLine();
        const party = readLine();
        data.set(name, [0, party]);
    }
    const m = parseInt(readLine(), 10);
    let mx = 0;
    for(let i = 0; i < m; ++i) {
        const name = readLine();
        if (!data.has(name)) continue;
        const [soFar, party] = data.get(name);
        data.set(name, [soFar + 1, party]);
        mx = Math.max(mx, soFar + 1);
    }
    let f = 0, ans;

    data.forEach((el, key) => {
        f += el[0] === mx;
        if (el[0] === mx) {
            ans = key;
        }
    });
    if (f > 1) {
        process.stdout.write("tie");
    }
    else {
        process.stdout.write(data.get(ans)[1]);
    }

}
