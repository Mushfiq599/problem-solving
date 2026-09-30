function subsets(nums) {
    const result = [];
    const current = [];

    function backtrack(start) {
        result.push([...current]);
        for (let i = start; i < nums.length; i++) {
            current.push(nums[i]);
            backtrack(i + 1);
            current.pop();
        }
    }

    backtrack(0);
    return result;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const nums = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
console.log(subsets(nums).map(s => '[' + s.join(',') + ']').join(' '));