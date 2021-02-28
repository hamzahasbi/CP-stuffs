function digPow(n, p){
    var sum = 0;
    var copy = n;
    var len = Math.floor(Math.log(n) / Math.log(10));
    p += len;
    while(n > 0) {
      sum += Math.pow(n % 10, p);
      p -= 1;
      n = Math.floor(n / 10);
    }
    return sum % copy == 0 ? sum / copy : -1;
}
console.log(digPow(89, 1), 1);
console.log(digPow(92, 1), -1);
console.log(digPow(46288, 3), 51);