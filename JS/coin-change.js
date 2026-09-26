function coinChange(coins, amount) {
  const dp = new Array(amount + 1).fill(Infinity);
  dp[0] = 0;

  for (let i = 1; i <= amount; i++) {
    for (const coin of coins) {
      if (coin <= i && dp[i - coin] + 1 < dp[i]) {
        dp[i] = dp[i - coin] + 1;
      }
    }
  }

  return dp[amount] === Infinity ? -1 : dp[amount];
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const numCoins = parseInt(lines[0]);
const coins = lines[1].trim().split(/\s+/).map(Number).slice(0, numCoins);
const amount = parseInt(lines[2]);
console.log(coinChange(coins, amount));