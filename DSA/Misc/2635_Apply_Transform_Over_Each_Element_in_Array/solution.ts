// 2635. Apply Transform Over Each Element in Array
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// LeetCode   : https://leetcode.com/problems/apply-transform-over-each-element-in-array/

function map(arr: number[], fn: (n: number, i: number) => number): number[] {
    var res = [];
    for(var i =0; i<arr.length;i++)
    {
        res.push(fn(arr[i],i));
    }
    return res;
};