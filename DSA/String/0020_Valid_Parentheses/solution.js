// 0020. Valid Parentheses
// Difficulty : Easy
// Tags       : string, stack
// Solved on  : 2026-04-23
// LeetCode   : https://leetcode.com/problems/valid-parentheses/

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    var stack = [];
    var maping = {')' : '(','}' : '{' , ']' : '['};
    for(c of s){
        if (c in maping){
            if (stack.length == 0 || stack.pop() != maping[c]){
                return false;
            }
        }
        else stack.push(c)
    }
    return stack.length == 0
};