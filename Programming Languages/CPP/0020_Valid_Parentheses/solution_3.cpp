// 0020. Valid Parentheses
// Difficulty : Easy
// Tags       : string, stack
// Solved on  : 2020-12-17
// Attempt    : #3
// LeetCode   : https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s)
        {
            if(c=='(' || c=='{' || c=='[')
            {
                st.push(c);
            }
            else if(c==')' || c=='}' || c==']')
            {   if(st.empty())
                    return false;
                char ch=st.top();
                if(c==')'){
                    if(ch!='(') return false; 
                }
                else if(c=='}')
                {
                    if(ch!='{') return false;
                }
                else if(c==']')
                {
                    if(ch!='[') return false;
                }
                st.pop();
            }
            
            
           
        }
        if(st.empty()) return true;
        return false;
    }
};