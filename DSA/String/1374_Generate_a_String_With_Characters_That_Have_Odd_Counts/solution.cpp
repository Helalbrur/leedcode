// 1374. Generate a String With Characters That Have Odd Counts
// Difficulty : Easy
// Tags       : string
// Solved on  : 2020-03-08
// LeetCode   : https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/

class Solution {
public:
    string generateTheString(int n) {
        string s;
        if(n%2){
            for(int i=1;i<=n;i++){
                s+='a';
            }
        }
        else{
            s+='a';
            for(int i=2;i<=n;i++){
                s+='b';
            }
        }
        return s;
    }
};