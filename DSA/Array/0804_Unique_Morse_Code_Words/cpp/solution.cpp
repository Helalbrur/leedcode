// 0804. Unique Morse Code Words
// Difficulty : Easy
// Tags       : array, hash-table, string
// Solved on  : 2019-08-22
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/unique-morse-code-words/

class Solution {
public:
    char cov[26][20]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    int uniqueMorseRepresentations(vector<string>& words) { 
        
        map<string,int> mp;
        for(int i=0;i<words.size();i++){
            string a;
            for(int j=0;j<words[i].length();j++){
                a+=cov[words[i][j]-'a'];
            }
            mp[a]++;
        }
        
        int cnt=0;
        
        for(auto it= mp.begin();it!=mp.end();++it){
            cnt++;
        }
        
        return cnt;
       
    }
};