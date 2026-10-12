function isPowerOfTwo(n) {
  if (n <= 0) return false;
  return (n & (n - 1)) === 0;
}

const n = parseInt(require('fs').readFileSync('/dev/stdin', 'utf8').trim());
console.log(isPowerOfTwo(n) ? 'YES' : 'NO');