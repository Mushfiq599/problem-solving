function maxArea(h) {
  let l = 0, r = h.length - 1, best = 0;
  while (l < r) {
    best = Math.max(best, Math.min(h[l], h[r]) * (r - l));
    if (h[l] < h[r]) l++;
    else r--;
  }
  return best;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const h = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
console.log(maxArea(h));