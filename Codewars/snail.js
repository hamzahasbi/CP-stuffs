snail = function(lst) {
    let i = 0, szx = lst.length;
    if (szx == 0) return [];
    let ans = [];
    let dx = 1, dy = 1;
    let szy = lst[0].length;
    while(i < szx) {
        let j = 0;
        let data = [];
        while (j < szy) {
            data.push(lst[i][j]);
            if (dx == 1) j += dx;
            else szy += dx;
        }
        ans.push(data);
    }
    return ans;
};
console.log(snail([[1,2,3],[4,5,6],[7,8,9]]));