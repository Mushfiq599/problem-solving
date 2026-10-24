class ListNode {
  constructor(val, next = null) {
    this.val = val;
    this.next = next;
  }
}

function build(arr) {
  const dummy = new ListNode(0);
  let cur = dummy;
  for (const v of arr) {
    cur.next = new ListNode(v);
    cur = cur.next;
  }
  return dummy.next;
}

function mergeTwoLists(a, b) {
  const dummy = new ListNode(0);
  let tail = dummy;

  while (a && b) {
    if (a.val <= b.val) {
      tail.next = a;
      a = a.next;
    } else {
      tail.next = b;
      b = b.next;
    }
    tail = tail.next;
  }
  tail.next = a || b; // attach whatever remains

  return dummy.next;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const [n, m] = lines[0].trim().split(/\s+/).map(Number);
const parse = (line, len) =>
  (line || '').trim().split(/\s+/).filter(Boolean).map(Number).slice(0, len);

const l1 = build(parse(lines[1], n));
const l2 = build(parse(lines[2], m));

const out = [];
for (let node = mergeTwoLists(l1, l2); node; node = node.next) out.push(node.val);
console.log(out.join(' '));