// 2703. Return Length of Arguments Passed
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-29
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/return-length-of-arguments-passed/

/**
 * @param {...(null|boolean|number|string|Array|Object)} args
 * @return {number}
 */
var argumentsLength = function(...args) {
    var i = 0;
    for(var x of args)
    {
        i++;
    }
    return i;
};

/**
 * argumentsLength(1, 2, 3); // 3
 */