function singleNumber(arr) {
  let result = 0;
  for (const num of arr) {
    result ^= num;
  }
  return result;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
console.log(singleNumber(arr));