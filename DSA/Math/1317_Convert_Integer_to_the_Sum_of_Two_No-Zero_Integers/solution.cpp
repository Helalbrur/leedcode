// 1317. Convert Integer to the Sum of Two No-Zero Integers
// Difficulty : Easy
// Tags       : math
// Solved on  : 2020-01-12
// LeetCode   : https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
       vector<int> v;
       for(int i=1;i<=n;i++){
           for(int j=i;j<=n;j++){
               pair<int,int> p,q;
               p=bitcount(i);
               q=bitcount(j);
               if(i+j==n && p.first==p.second && q.first==q.second){
                   v.push_back(i);
                   v.push_back(j);
                   return v;
               }
           }
       }
      return v;
    }
    pair<int,int> bitcount(int n){
        int b=0,s=0;
        while(n){
            s++;
            if(n%10){
                b++;
            }
            n=n/10;
        }
        return make_pair(b,s);
    }
};