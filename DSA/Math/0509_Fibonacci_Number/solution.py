# 0509. Fibonacci Number
# Difficulty : Easy
# Tags       : math, dynamic-programming, recursion, memoization
# Solved on  : 2022-07-07
# LeetCode   : https://leetcode.com/problems/fibonacci-number/

class Solution:
    def fib(self, n: int) -> int:
        return f(self,n)
def f(self , n: int) -> int:
    if n == 0:
        return 0
    if n == 1:
        return 1
    return f(self , n-1)+f(self , n-2)