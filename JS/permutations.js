function permute(nums) {
  const result = [];
  const used = new Array(nums.length).fill(false);
  const current = [];

  function backtrack() {
    if (current.length === nums.length) {
      result.push([...current]);
      return;
    }
    for (let i = 0; i < nums.length; i++) {
      if (used[i]) continue;
      used[i] = true;
      current.push(nums[i]);
      backtrack();
      current.pop();
      used[i] = false;
    }
  }

  backtrack();
  return result;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const nums = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
console.log(permute(nums).map(p => '[' + p.join(',') + ']').join(' '));