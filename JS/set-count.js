function countSetBits(n) {
  let count = 0;
  while (n > 0) {
    count += n & 1;
    n >>>= 1; // unsigned right shift
  }
  return count;
}

const n = parseInt(require('fs').readFileSync('/dev/stdin', 'utf8').trim());
console.log(countSetBits(n));