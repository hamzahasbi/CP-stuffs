function process(b) {
    let tmp = 0;
    b.split('').forEach(element => {
        tmp += Number(element);
    });
    return tmp;
}
function orderWeight(strng) {
    let arrayOfShit = strng.split(' ');
    let answer = arrayOfShit.sort(function compare(a, b) {
        let aa = process(a);
        let bb = process(b);
        return aa - bb;
    });
    return answer.join(' ');
}
console.log(orderWeight("103 123 4444 99 2000"))
console.log(orderWeight("2000 10003 1234000 44444444 9999 11 11 22 123"))