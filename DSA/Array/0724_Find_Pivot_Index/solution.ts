// 0724. Find Pivot Index
// Difficulty : Easy
// Tags       : array, prefix-sum
// Solved on  : 2022-07-07
// LeetCode   : https://leetcode.com/problems/find-pivot-index/

function pivotIndex(nums: number[]): number {
    var sum = 0;
    for ( var i = 0 ; i < nums.length ; i++ )
    {
          sum += nums[i];  
    }
    var s = 0;
    for ( var i = 0 ; i < nums.length ; i++ )
    {
        if(s * 2 == sum - nums[i]) return i ;
        s += nums[i];
    }
    return -1;
};