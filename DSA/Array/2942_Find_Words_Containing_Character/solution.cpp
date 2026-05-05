// 2942. Find Words Containing Character
// Difficulty : Easy
// Tags       : array, string
// Solved on  : 2025-10-20
// LeetCode   : https://leetcode.com/problems/find-words-containing-character/

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i= 0; i<words.size();i++)
        {
            for(int j=0;j<words[i].length();j++)
            {
                if(words[i][j] == x){
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};