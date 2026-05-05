// 0009. Palindrome Number
// Difficulty : Easy
// Tags       : math
// Solved on  : 2018-12-05
// LeetCode   : https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0)
            return true;
        if(x<0 ||(x%10==0 )){
            return false;
            
        }
        int n=0,temp;
        while(n<x){
            int r=x%10;
            temp=x;
            x=x/10;
            n=n*10+r;
            
            
            
            
        }
       if(n==temp||x==n)
        return true;
        return false;
        
    }
};