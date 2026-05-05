// 0771. Jewels and Stones
// Difficulty : Easy
// Tags       : hash-table, string
// Solved on  : 2019-08-10
// LeetCode   : https://leetcode.com/problems/jewels-and-stones/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int a[56];
        memset(a,0,sizeof(a));
        for(int i=0;i<J.length();i++){
            if(J[i]>='A' && J[i]<='Z'){
                a[J[i]-'A'+26]++;
            }else{
                a[J[i]-'a']++;
            }
        }
        int cnt=0;
         for(int i=0;i<S.length();i++){
            if(S[i]>='A' && S[i]<='Z'){
                if(a[S[i]-'A'+26]>0){
                    cnt++;
                }
            }else if(a[S[i]-'a']>0){
                cnt++;
            }
        }
        return cnt;
    }
};