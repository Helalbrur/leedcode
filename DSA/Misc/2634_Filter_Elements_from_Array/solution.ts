// 2634. Filter Elements from Array
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// LeetCode   : https://leetcode.com/problems/filter-elements-from-array/

type Fn = (n: number, i: number) => any

function filter(arr: number[], fn: Fn): number[] {
    var res: number[] = [];
    for(var i: number =0; i<arr.length;i++)
    {
        if(fn(arr[i],i))
        {
            res.push(arr[i]);
        }
        
    }
    return res;
};