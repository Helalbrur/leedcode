// 1480. Running Sum of 1d Array
// Difficulty : Easy
// Tags       : array, prefix-sum
// Solved on  : 2022-07-07
// LeetCode   : https://leetcode.com/problems/running-sum-of-1d-array/

function runningSum(nums: number[]): number[] {
    var sum = 0;
    for( var i = 0 ; i < nums.length ; i++)
    {
        sum += nums[i];
        nums[i] = sum;
    }
    return nums ;
};