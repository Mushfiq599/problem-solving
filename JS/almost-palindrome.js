function isPalindromeRange(str, left, right) {
    while (left < right) {
        if (str[left] !== str[right]) return false;
        left++;
        right--;
    }
    return true;
}

function almostPalindrome(str) {
    let left = 0;
    let right = str.length - 1;

    while (left < right) {
        if (str[left] !== str[right]) {
            return isPalindromeRange(str, left + 1, right) ||
                isPalindromeRange(str, left, right - 1);
        }
        left++;
        right--;
    }

    return true;
}

// --- Read input from stdin ---
const input = require('fs').readFileSync('/dev/stdin', 'utf8').trim();
console.log(almostPalindrome(input) ? 'YES' : 'NO');