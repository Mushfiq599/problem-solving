function knapsack(weights, values, capacity) {
    const n = weights.length;
    const dp = Array.from({ length: n + 1 }, () => new Array(capacity + 1).fill(0));

    for (let i = 1; i <= n; i++) {
        for (let w = 0; w <= capacity; w++) {
            dp[i][w] = dp[i - 1][w]; // don't take item i
            if (weights[i - 1] <= w) {
                dp[i][w] = Math.max(dp[i][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            }
        }
    }

    return dp[n][capacity];
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const weights = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
const values = lines[2].trim().split(/\s+/).map(Number).slice(0, n);
const capacity = parseInt(lines[3]);
console.log(knapsack(weights, values, capacity));