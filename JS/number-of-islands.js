function numIslands(grid) {
  const rows = grid.length, cols = grid[0].length;

  function dfs(r, c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] !== 1) return;
    grid[r][c] = 0;
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
  }

  let count = 0;
  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (grid[r][c] === 1) {
        count++;
        dfs(r, c);
      }
    }
  }
  return count;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [rows, cols] = lines[0].split(' ').map(Number);
const grid = [];
for (let i = 1; i <= rows; i++) grid.push(lines[i].trim().split(/\s+/).map(Number));

console.log(numIslands(grid));