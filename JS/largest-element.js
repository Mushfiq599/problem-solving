class MinHeap {
  constructor() { this.heap = []; }
  size() { return this.heap.length; }
  peek() { return this.heap[0]; }

  push(val) {
    this.heap.push(val);
    let i = this.heap.length - 1;
    while (i > 0) {
      const parent = (i - 1) >> 1;
      if (this.heap[parent] <= this.heap[i]) break;
      [this.heap[parent], this.heap[i]] = [this.heap[i], this.heap[parent]];
      i = parent;
    }
  }

  pop() {
    const top = this.heap[0];
    const last = this.heap.pop();
    if (this.heap.length) {
      this.heap[0] = last;
      let i = 0;
      while (true) {
        let left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < this.heap.length && this.heap[left] < this.heap[smallest]) smallest = left;
        if (right < this.heap.length && this.heap[right] < this.heap[smallest]) smallest = right;
        if (smallest === i) break;
        [this.heap[i], this.heap[smallest]] = [this.heap[smallest], this.heap[i]];
        i = smallest;
      }
    }
    return top;
  }
}

function findKthLargest(arr, k) {
  const heap = new MinHeap();
  for (const num of arr) {
    heap.push(num);
    if (heap.size() > k) heap.pop();
  }
  return heap.peek();
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
const k = parseInt(lines[2]);
console.log(findKthLargest(arr, k));