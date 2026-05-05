// 1362. Closest Divisors
// Difficulty : Medium
// Tags       : math
// Solved on  : 2020-02-23
// LeetCode   : https://leetcode.com/problems/closest-divisors/


class Solution {
public:
    vector<int> closestDivisors(int num) {
        vector<int> v;
        int a,b;
        int dif=INT_MAX;
         for(int i=sqrt(num+1);i>=1;i--){
            if((num+1)%i==0){
               
                if(abs(i-(num+1)/i)<dif){
                    dif=abs(i-(num+1)/i);
                    a=i;
                    b=(num+1)/i;
                }
            }
        }
         for(int i=sqrt(num+2);i>=1;i--){
            if((num+2)%i==0){
               
                if(abs(i-(num+2)/i)<dif){
                    dif=abs(i-(num+2)/i);
                    a=i;
                    b=(num+2)/i;
                }
            }
        }
        v.push_back(a);
        v.push_back(b);
        sort(v.begin(),v.end());
        return v;
    }
};