// 2667. Create Hello World Function
// Difficulty : Easy
// Tags       : 
// Solved on  : 2023-12-19
// LeetCode   : https://leetcode.com/problems/create-hello-world-function/

/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */