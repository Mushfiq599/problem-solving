
function findDuplicates(arr) {
    let seen = new Set();
    let duplicates = [];
    
    for (let i = 0; i < arr.length; i++) {
        if (seen.has(arr[i])) {
            
            if (!duplicates.includes(arr[i])) {
                duplicates.push(arr[i]);
            }
        } else {
            seen.add(arr[i]); 
        }
    }
    return duplicates;
}

console.log(findDuplicates([1, 3, 5, 3, 7, 1])); 