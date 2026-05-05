// 2677. Chunk Array
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-29
// LeetCode   : https://leetcode.com/problems/chunk-array/

/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    var ret_arr = [];
    for(var i = 0; i<arr.length ; i+=size)
    {
        var chunck_arr = arr.slice(i,Math.min(i+size,arr.length));
        ret_arr.push(chunck_arr);
    }
    return ret_arr;
};
