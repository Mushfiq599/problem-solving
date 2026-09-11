function isBalanced(str) {
    const stack = [];
    const pairs = { ')': '(', ']': '[', '}': '{' };
    const opens = new Set(['(', '[', '{']);

    for (const ch of str) {
        if (opens.has(ch)) {
            stack.push(ch);
        } else if (ch === ')' || ch === ']' || ch === '}') {
            if (stack.pop() !== pairs[ch]) return false;
        }
        // any other character is ignored
    }

    return stack.length === 0;
}

// --- Read input from stdin ---
const input = require('fs').readFileSync('/dev/stdin', 'utf8').replace(/\n$/, '');
console.log(isBalanced(input) ? 'YES' : 'NO');