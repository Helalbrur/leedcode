// 2626. Array Reduce Transformation
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// LeetCode   : https://leetcode.com/problems/array-reduce-transformation/

type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    var sum: number = init;
    for(var i: number = 0; i < nums.length; i++)
    {
        sum = (fn(sum,nums[i]))
    }
    return sum;
};