// 2727. Is Object Empty
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-29
// LeetCode   : https://leetcode.com/problems/is-object-empty/

/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    if(typeof obj === "object"  ) return Object.keys(obj).length === 0;
    return obj.length === 0;
};