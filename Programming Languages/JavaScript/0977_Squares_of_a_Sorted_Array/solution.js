// 0977. Squares of a Sorted Array
// Difficulty : Easy
// Tags       : array, two-pointers, sorting
// Solved on  : 2026-05-14
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/squares-of-a-sorted-array/

/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortedSquares = function(nums) {
    return nums.map(n => n *n)
                .sort((a,b)=>a-b);
};