// 1021. Remove Outermost Parentheses
// Difficulty : Easy
// Tags       : string, stack
// Solved on  : 2019-08-22
// LeetCode   : https://leetcode.com/problems/remove-outermost-parentheses/

class Solution {
public:
    string removeOuterParentheses(string S) {
        int cnt=0;
        string a;
        for(int i=0;i<S.length();i++){
            if(S[i]==')'){
                cnt--;
            }
            if(cnt>0){
                a+=S[i];
            }
            if(S[i]=='('){
                cnt++;
            }
        }
        return a;
    }
};