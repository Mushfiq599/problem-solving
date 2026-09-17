function firstMissingPositive(arr) {
    const n = arr.length;
    for (let i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] !== arr[i]) {
            const target = arr[i] - 1;
            [arr[i], arr[target]] = [arr[target], arr[i]];
        }
    }
    for (let i = 0; i < n; i++) {
        if (arr[i] !== i + 1) return i + 1;
    }
    return n + 1;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
console.log(firstMissingPositive(arr));