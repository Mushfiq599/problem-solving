function canFinish(numCourses, prereqs) {
  const graph = Array.from({ length: numCourses }, () => []);
  for (const [a, b] of prereqs) graph[b].push(a);

  const state = new Array(numCourses).fill(0); // 0=unvisited, 1=visiting, 2=done

  function hasCycle(node) {
    if (state[node] === 1) return true;
    if (state[node] === 2) return false;

    state[node] = 1;
    for (const next of graph[node]) {
      if (hasCycle(next)) return true;
    }
    state[node] = 2;
    return false;
  }

  for (let i = 0; i < numCourses; i++) {
    if (hasCycle(i)) return false;
  }
  return true;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split('\n');
const [numCourses, numPrereqs] = lines[0].split(' ').map(Number);
const prereqs = [];
for (let i = 1; i <= numPrereqs; i++) prereqs.push(lines[i].trim().split(' ').map(Number));

console.log(canFinish(numCourses, prereqs) ? 'YES' : 'NO');