function search(a, target) {
  let lo = 0, hi = a.length - 1;

  while (lo <= hi) {
    const mid = Math.floor((lo + hi) / 2);
    if (a[mid] === target) return mid;

    if (a[lo] <= a[mid]) { // left half is sorted
      if (a[lo] <= target && target < a[mid]) hi = mid - 1;
      else lo = mid + 1;
    } else {               // right half is sorted
      if (a[mid] < target && target <= a[hi]) lo = mid + 1;
      else hi = mid - 1;
    }
  }
  return -1;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const a = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
const target = parseInt(lines[2]);
console.log(search(a, target));