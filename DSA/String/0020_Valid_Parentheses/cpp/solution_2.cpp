// 0020. Valid Parentheses
// Difficulty : Easy
// Tags       : string, stack
// Solved on  : 2020-12-17
// Attempt    : #2
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
            {   if(st.size()<=0)
                    return false;
                if(c==')'){
                    char ch=st.top();
                    if(ch!='(') return false;
                    st.pop();
                }
                else if(c=='}')
                {
                    char ch=st.top();
                    if(ch!='{') return false;
                     st.pop();
                }
                else if(c==']')
                {
                    char ch=st.top();
                    if(ch!='[') return false;
                     st.pop();
                }
            }
            
            
           
        }
        if(st.size()>0) return false;
        return true;
    }
};