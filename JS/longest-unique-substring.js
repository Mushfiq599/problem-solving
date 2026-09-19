function longestUniqueSubstring(str) {
    const lastSeen = new Map();
    let maxLen = 0;
    let start = 0;

    for (let i = 0; i < str.length; i++) {
        const ch = str[i];
        if (lastSeen.has(ch) && lastSeen.get(ch) >= start) {
            start = lastSeen.get(ch) + 1;
        }
        lastSeen.set(ch, i);
        maxLen = Math.max(maxLen, i - start + 1);
    }

    return maxLen;
}

const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim();
console.log(longestUniqueSubstring(input));