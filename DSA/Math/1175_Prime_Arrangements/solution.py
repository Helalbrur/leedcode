# 1175. Prime Arrangements
# Difficulty : Easy
# Tags       : math
# Solved on  : 2019-09-01
# LeetCode   : https://leetcode.com/problems/prime-arrangements/

def fact(n):
    f=1
    for i in range(1,n+1):
        f=f*i
    return f
def isPrime(n):
    if(n<2):
        return 0
    if(n==2):
        return 1
    for i in range(2,n):
        if(n%i==0):
            return 0
    return 1
class Solution(object):
    def numPrimeArrangements(self, n):
        if(n<=2):
            return 1
        cnt=0
        for i in range(1,n+1):
            if(isPrime(i)==1):
                cnt=cnt+1
        return (fact(cnt)*fact(n-cnt))%1000000007
   