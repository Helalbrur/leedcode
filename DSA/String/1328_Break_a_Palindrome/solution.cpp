// 1328. Break a Palindrome
// Difficulty : Medium
// Tags       : string, greedy
// Solved on  : 2020-01-25
// LeetCode   : https://leetcode.com/problems/break-a-palindrome/

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int len=palindrome.length();
        if(len<=1){
            return "";
        }
        int m=len/2;
       
        for(int i=0;i<len;i++){
            if(i!=m || len%2!=1){
                int c=palindrome[len-i-1]-'a';
                if(c>0){
                    palindrome[i]='a';
                    return palindrome;
                }
            }
        }
        if(palindrome[0]=='b'){
            palindrome[0]='a';
            return palindrome;
        }
        palindrome[len-1]='b';
        return palindrome;
        
    }
};