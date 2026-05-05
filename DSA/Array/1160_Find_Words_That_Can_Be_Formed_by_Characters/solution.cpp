// 1160. Find Words That Can Be Formed by Characters
// Difficulty : Easy
// Tags       : array, hash-table, string, counting
// Solved on  : 2019-08-18
// LeetCode   : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int a[27];
        memset(a,0,sizeof(a));
        for(int i=0;i<chars.length();i++){
            a[chars[i]-'a']++;
        }
         
        int cnt=0;
        for(int i=0;i<words.size();i++){
            int b[27];
            memset(b,0,sizeof(b));
            for(int j=0;j<words[i].length();j++){
                b[words[i][j]-'a']++;
            }
            int flag=0;
            for(int j=0;j<26;j++){
                if(a[j]<b[j]){
                    flag=1;
                }
            }
            if(flag==0){
                cnt+=words[i].length();
            }
        }
        return cnt;
        
    }
};