// 1003. Check If Word Is Valid After Substitutions
// Difficulty : Medium
// Tags       : string, stack
// Solved on  : 2021-02-12
// LeetCode   : https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
   let subS = s.split('abc').join('');
    while(subS.length < s.length){
         s = subS;
         subS = s.split('abc').join('') ;
    }
    
    return s.length === 0;
    
};