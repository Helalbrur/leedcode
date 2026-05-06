// 0001. Two Sum
// Difficulty : Easy
// Tags       : array, hash-table
// Solved on  : 2022-06-13
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/two-sum/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for(let i=0;i<nums.length;i++)
    {
        for(let j=0;j<i;j++) if(nums[i]+nums[j]==target) return [j,i];
    }
};