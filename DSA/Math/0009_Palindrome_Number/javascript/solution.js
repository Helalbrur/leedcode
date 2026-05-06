// 0009. Palindrome Number
// Difficulty : Easy
// Tags       : math
// Solved on  : 2022-06-12
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/palindrome-number/

/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let y=x.toString();
    let ret='';
    for(let i=y.length-1;i>=0; i--)
    {
        ret+=y[i];
    }
    return y==ret; 
};