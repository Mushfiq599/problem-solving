function longestIncreasingStreak(arr) {
    if (arr.length === 0) return 0;

    let maxLen = 1;
    let curLen = 1;

    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > arr[i - 1]) {
            curLen++;
        } else {
            curLen = 1;
        }
        maxLen = Math.max(maxLen, curLen);
    }

    return maxLen;
}

// --- Read input from stdin ---
const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).map(Number).slice(0, n);

console.log(longestIncreasingStreak(arr));