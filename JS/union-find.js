function countComponents(n, edges) {
  const parent = Array.from({ length: n }, (_, i) => i);
  const size = new Array(n).fill(1);

  function find(x) {
    while (parent[x] !== x) {
      parent[x] = parent[parent[x]]; // path compression
      x = parent[x];
    }
    return x;
  }

  let components = n;
  for (const [a, b] of edges) {
    let ra = find(a), rb = find(b);
    if (ra === rb) continue;
    if (size[ra] < size[rb]) [ra, rb] = [rb, ra];
    parent[rb] = ra;
    size[ra] += size[rb];
    components--;
  }
  return components;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [n, m] = lines[0].split(' ').map(Number);
const edges = [];
for (let i = 1; i <= m; i++) edges.push(lines[i].trim().split(' ').map(Number));
console.log(countComponents(n, edges));