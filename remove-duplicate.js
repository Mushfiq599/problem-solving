
function removeDuplicates(arr) {
    let seen = new Set();
    let result = [];
    
    for (let i = 0; i < arr.length; i++) {
        if (!seen.has(arr[i])) {
            seen.add(arr[i]);
            result.push(arr[i]);
        }
    }
    return result;
}

console.log(removeDuplicates([1, 2, 2, 3, 4, 4, 5])); 