// 0001. Two Sum
// Difficulty : Easy
// Tags       : array, hash-table
// Solved on  : 2026-04-19
// LeetCode   : https://leetcode.com/problems/two-sum/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var taken = {};
    for (const [ind,val] of nums.entries())
    {
        const sub = target - val;
        if (sub in taken){
            return [taken[sub],ind];
        }
        taken[val] = ind;
    }
};