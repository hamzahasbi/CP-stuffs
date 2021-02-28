const Sieve = N => {
  let primes = [];
  let isPrime = new Array(N);
  isPrime[0] = false;
  isPrime[1] = false;
  isPrime.fill(true, 2, N);

  for (let i = 2; i * i <= N; ++i) {
    if (isPrime[i]) {
      primes.push(i);
      let mult = 2 * i;
      while (mult <= N) {
        isPrime[mult] = false;
        mult += i;
      }
    }
  }
  return primes;
};

function decomp(n) {
  const primes = Sieve(n * n);

  let count = new Array(n + 1);

  count.fill(0, 0, n + 1);
  for (let i = 2; i <= n; ++i) {
    primes.forEach(value => {
      if (value > i) return;
      let j = i;
      while (j % value === 0 && j > 0 && j >= value) {
        count[value] += 1;
        j /= value;
      }
    });
  }

  let result = "";
  primes.forEach(value => {
    if (count[value] > 0) {
        if (count[value] > 1) {
            result += value + "^" + count[value] + " * ";
        } else {
            result += value + " * ";
        }
    }
  });

  return result.slice(0, -3);
}

console.assert(decomp(17), "2^15 * 3^6 * 5^3 * 7^2 * 11 * 13 * 17");
console.assert(decomp(5), "2^3 * 3 * 5");
console.assert(decomp(22), "2^19 * 3^9 * 5^4 * 7^3 * 11^2 * 13 * 17 * 19");
console.assert(decomp(14), "2^11 * 3^5 * 5^2 * 7^2 * 11 * 13");
console.assert(decomp(25), "2^22 * 3^10 * 5^6 * 7^3 * 11^2 * 13 * 17 * 19 * 23");
