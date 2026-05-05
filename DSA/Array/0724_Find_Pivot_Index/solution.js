// 0724. Find Pivot Index
// Difficulty : Easy
// Tags       : array, prefix-sum
// Solved on  : 2022-07-07
// LeetCode   : https://leetcode.com/problems/find-pivot-index/

/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    var sum = 0 ;
    for ( var i = 0 ; i < nums.length ; i++ )
    {
         sum += nums[i];   
    }
    
    var s = 0 ;
    for ( var i = 0 ; i < nums.length ; i++ )
    {
        if ( sum - s - nums[i] == s) return i;
         s += nums[i];   
    }
    return -1;
};