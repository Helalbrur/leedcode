// 0509. Fibonacci Number
// Difficulty : Easy
// Tags       : math, dynamic-programming, recursion, memoization
// Solved on  : 2022-07-07
// LeetCode   : https://leetcode.com/problems/fibonacci-number/

/**
 * @param {number} n
 * @return {number}
 */
var fib = function(n) {
    return f(n);
};

function f(n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    return f(n-1)+f(n-2);
}