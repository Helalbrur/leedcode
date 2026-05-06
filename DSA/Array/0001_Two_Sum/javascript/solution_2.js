// 0001. Two Sum
// Difficulty : Easy
// Tags       : array, hash-table
// Solved on  : 2026-04-19
// Attempt    : #2
// LeetCode   : https://leetcode.com/problems/two-sum/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var taken = {};
    for(var i = 0; i<nums.length;i++){
        var sub = target - nums[i];
        if (sub in taken){
            return [taken[sub],i];
        }
        taken[nums[i]] = i;
    }
};