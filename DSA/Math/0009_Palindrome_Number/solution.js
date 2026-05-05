// 0009. Palindrome Number
// Difficulty : Easy
// Tags       : math
// Solved on  : 2026-04-21
// LeetCode   : https://leetcode.com/problems/palindrome-number/

/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    return x >= 0 && x.toString().split("").reverse().join("") == x.toString();
};