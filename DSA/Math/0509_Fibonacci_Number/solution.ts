// 0509. Fibonacci Number
// Difficulty : Easy
// Tags       : math, dynamic-programming, recursion, memoization
// Solved on  : 2022-07-07
// LeetCode   : https://leetcode.com/problems/fibonacci-number/

function fib(n: number): number {
    return f( n );
};

function f(n: number): number{
    if( n == 0 ) return 0;
    if( n == 1 ) return 1;
    return f( n-1 ) + f( n-2 );
}