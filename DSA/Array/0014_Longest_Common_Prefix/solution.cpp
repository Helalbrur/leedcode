// 0014. Longest Common Prefix
// Difficulty : Easy
// Tags       : array, string, trie
// Solved on  : 2023-01-07
// LeetCode   : https://leetcode.com/problems/longest-common-prefix/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = 1000;
        for(int i = 0 ; i < strs.size(); i++)
        {
            min_len = _min(min_len,strs[0].length());
        }
        string result = strs[0].substr(0,min_len);
        for(int i = 0 ; i < strs.size(); i++)
        {
            for(int j = 0 ; j < min_len; j++)
            {
                if(strs[0][j] != strs[i][j])
                {
                    if(result.length() > j)
                    {
                        result = strs[0].substr(0,j);
                        break;
                    }
                }
            }
        }
        return result;
    }
    public: int _min(int a,int b)
    {
        if(a < b) return a; else return b;
    } 
};