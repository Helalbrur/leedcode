// 2634. Filter Elements from Array
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// LeetCode   : https://leetcode.com/problems/filter-elements-from-array/

/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    var res = [];
    for(var i =0; i<arr.length;i++)
    {
        if(fn(arr[i],i))
        {
            res.push(arr[i]);
        }
        
    }
    return res;
};