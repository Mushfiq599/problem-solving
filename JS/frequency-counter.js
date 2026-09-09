function mostFrequent(arr) {
    const freq = new Map();
    let bestNum = null;
    let bestCount = 0;

    for (const num of arr) {
        const count = (freq.get(num) || 0) + 1;
        freq.set(num, count);

        if (
            count > bestCount ||
            (count === bestCount && num < bestNum)
        ) {
            bestCount = count;
            bestNum = num;
        }
    }

    return bestNum;
}

// --- Read input from stdin ---
const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).map(Number).slice(0, n);

console.log(mostFrequent(arr));