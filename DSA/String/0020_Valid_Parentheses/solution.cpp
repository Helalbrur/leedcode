// 0020. Valid Parentheses
// Difficulty : Easy
// Tags       : string, stack
// Solved on  : 2021-02-12
// LeetCode   : https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c:s)
        {
            if(c=='(' || c=='{' || c=='[')
            {
                st.push(c);
            }
            
            else if(st.size())
            {
               char t=st.top();
               st.pop();
               if(c==')' && t=='(') continue;
               else if(c=='}' && t=='{') continue;
               else if(c==']' && t=='[') continue;
               else return false;
            }
            else return false;
        }
        if(st.size()) return false;
        return true;
    }
};