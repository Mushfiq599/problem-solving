function moveZeroes(arr) {
    let insertPos = 0;
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] !== 0) {
            arr[insertPos++] = arr[i];
        }
    }
    while (insertPos < arr.length) arr[insertPos++] = 0;
    return arr;
}

const lines = require('fs').readFileSync('/dev/stdin', 'utf8').split('\n');
const n = parseInt(lines[0]);
const arr = lines[1].trim().split(/\s+/).map(Number).slice(0, n);
console.log(moveZeroes(arr).join(' '));