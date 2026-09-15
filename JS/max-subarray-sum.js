function maxSubarraySum(arr) {
    let maxSum = arr[0];
    let curSum = arr[0];

    for (let i = 1; i < arr.length; i++) {
        curSum = Math.max(arr[i], curSum + arr[i]);
        maxSum = Math.max(maxSum, curSum);
    }

    return maxSum;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
console.log(maxSubarraySum(arr));