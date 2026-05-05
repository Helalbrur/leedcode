// 1189. Maximum Number of Balloons
// Difficulty : Easy
// Tags       : hash-table, string, counting
// Solved on  : 2019-09-15
// LeetCode   : https://leetcode.com/problems/maximum-number-of-balloons/

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b=0,a=0,l=0,o=0,n=0;
        for(int i=0;i<text.length();i++){
           if(text[i]=='a'){
               a++;
           }else if(text[i]=='b'){
               b++;
           }else if(text[i]=='l'){
               l++;
           }else if(text[i]=='o'){
               o++;
           }else if(text[i]=='n'){
               n++;
           }
        }
        return min(b,min(a,min(l/2,min(o/2,n))));
        
    }
};