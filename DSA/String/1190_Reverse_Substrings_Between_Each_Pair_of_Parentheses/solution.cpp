// 1190. Reverse Substrings Between Each Pair of Parentheses
// Difficulty : Medium
// Tags       : string, stack
// Solved on  : 2019-09-15
// LeetCode   : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
public:
    string reverseParentheses(string s) {
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                cnt++;
            }
        }
        
       
        for(int i=0;i<cnt;i++){
            int p=0;
            for(int j=0;j<s.length();j++){
                if(s[j]=='('){
                    p=j;
                }
                
                if(s[j]==')'){
                    //cout<<s[p]<<endl;
                    s.erase(p,1);
                    // cout<<s[j-1]<<endl;
                    s.erase(j-1,1); 
                   
                    reverse(s.begin()+p,s.begin()+j-1);
                   // return s;
                    break;
                }
            }
        }
        return s;
    }
};