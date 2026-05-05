// 0709. To Lower Case
// Difficulty : Easy
// Tags       : string
// Solved on  : 2019-08-22
// LeetCode   : https://leetcode.com/problems/to-lower-case/

class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0;i<str.length();i++){
            if(str[i]>='A' && str[i]<='Z'){
                str[i]=str[i]-'A'+'a';
            }
        }
        return str;
    }
};