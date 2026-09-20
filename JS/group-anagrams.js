function groupAnagrams(strs) {
    const map = new Map();
    for (const s of strs) {
        const key = s.split('').sort().join('');
        if (!map.has(key)) map.set(key, []);
        map.get(key).push(s);
    }
    return [...map.values()];
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).slice(0, n);
const groups = groupAnagrams(arr);
console.log(groups.map(g => '[' + g.join(', ') + ']').join(' '));