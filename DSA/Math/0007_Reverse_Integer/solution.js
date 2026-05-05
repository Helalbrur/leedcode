// 0007. Reverse Integer
// Difficulty : Medium
// Tags       : math
// Solved on  : 2026-04-20
// LeetCode   : https://leetcode.com/problems/reverse-integer/

/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    var sign = x < 0 ? -1 : 1;
    var num = Number(Math.abs(x).toString().split("").reverse().join(""));
    const INT_MAX = (2 ** 31) - 1;
    return num > INT_MAX ? 0 : sign * num;

};