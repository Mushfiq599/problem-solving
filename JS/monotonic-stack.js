function nextGreater(arr) {
  const res = new Array(arr.length).fill(-1);
  const stack = []; // indices whose answer is still unknown

  for (let i = 0; i < arr.length; i++) {
    while (stack.length && arr[stack[stack.length - 1]] < arr[i]) {
      res[stack.pop()] = arr[i];
    }
    stack.push(i);
  }
  return res;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
console.log(nextGreater(arr).join(' '));