function subarraySum(arr, k) {
  const seen = new Map([[0, 1]]); // prefix sum -> how many times seen
  let sum = 0, count = 0;

  for (const x of arr) {
    sum += x;
    count += seen.get(sum - k) || 0;
    seen.set(sum, (seen.get(sum) || 0) + 1);
  }
  return count;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
const k = parseInt(lines[2]);
console.log(subarraySum(arr, k));