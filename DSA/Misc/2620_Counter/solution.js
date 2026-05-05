// 2620. Counter
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// LeetCode   : https://leetcode.com/problems/counter/

/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    
    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */