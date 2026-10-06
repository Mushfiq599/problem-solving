function totalNQueens(n) {
    const cols = new Set();
    const diag1 = new Set(); // row - col
    const diag2 = new Set(); // row + col
    let count = 0;

    function backtrack(row) {
        if (row === n) { count++; return; }
        for (let col = 0; col < n; col++) {
            if (cols.has(col) || diag1.has(row - col) || diag2.has(row + col)) continue;
            cols.add(col); diag1.add(row - col); diag2.add(row + col);
            backtrack(row + 1);
            cols.delete(col); diag1.delete(row - col); diag2.delete(row + col);
        }
    }

    backtrack(0);
    return count;
}

const n = parseInt(require('fs').readFileSync('/dev/stdin', 'utf8').trim());
console.log(totalNQueens(n));