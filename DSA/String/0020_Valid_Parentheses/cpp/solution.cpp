// 0020. Valid Parentheses
// Difficulty : Easy
// Tags       : string, stack
// Solved on  : 2019-08-10
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='[' ){
                st.push(s[i]);
            }
            else if(s[i]==')' ){
                if(st.size()==0){
                    return false;
                }
                char c=st.top();
                st.pop();
               
                if(c!='('){
                    return false;
                }
            }
            else if( s[i]=='}' ){
                if(st.size()==0){
                    return false;
                }
                char c=st.top();
                st.pop();
               
                if(c!='{'){
                    return false;
                }
            }
            else if( s[i]==']'){
                if(st.size()==0){
                    return false;
                }
                char c=st.top();
                st.pop();
               
                if(c!='['){
                    return false;
                }
            }
            
        }
        if(st.size()==0)
        {
            return true;
        }
        return false;
        
    }
};