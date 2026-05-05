// 2626. Array Reduce Transformation
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// LeetCode   : https://leetcode.com/problems/array-reduce-transformation/

/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    var sum = init;
    for(var i = 0; i < nums.length; i++)
    {
        sum = (fn(sum,nums[i]))
    }
    return sum;
};