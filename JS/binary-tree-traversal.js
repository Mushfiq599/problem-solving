class Node {
    constructor(val) { this.val = val; this.left = null; this.right = null; }
}

function buildTree(vals, idxRef) {
    if (idxRef.i >= vals.length || vals[idxRef.i] === -1) { idxRef.i++; return null; }
    const node = new Node(vals[idxRef.i++]);
    node.left = buildTree(vals, idxRef);
    node.right = buildTree(vals, idxRef);
    return node;
}

function levelOrder(root) {
    const result = [];
    if (!root) return result;
    let queue = [root];

    while (queue.length) {
        const level = [];
        const next = [];
        for (const node of queue) {
            level.push(node.val);
            if (node.left) next.push(node.left);
            if (node.right) next.push(node.right);
        }
        result.push(level);
        queue = next;
    }
    return result;
}

const vals = require('fs').readFileSync('/dev/stdin', 'utf8').trim().split(/\s+/).map(Number);
const root = buildTree(vals, { i: 0 });
console.log(levelOrder(root).map(l => '[' + l.join(', ') + ']').join(' '));