function exist(board, word) {
  const rows = board.length, cols = board[0].length;

  function dfs(r, c, idx) {
    if (idx === word.length) return true;
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] !== word[idx]) return false;

    const temp = board[r][c];
    board[r][c] = '#'; // mark visited

    const found = dfs(r + 1, c, idx + 1) ||
                  dfs(r - 1, c, idx + 1) ||
                  dfs(r, c + 1, idx + 1) ||
                  dfs(r, c - 1, idx + 1);

    board[r][c] = temp; // restore
    return found;
  }

  for (let r = 0; r < rows; r++) {
    for (let c = 0; c < cols; c++) {
      if (dfs(r, c, 0)) return true;
    }
  }
  return false;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [rows, cols] = lines[0].split(' ').map(Number);
const board = [];
for (let i = 1; i <= rows; i++) board.push(lines[i].trim().split(/\s+/));
const word = lines[rows + 1].trim();

console.log(exist(board, word) ? 'YES' : 'NO');