// 1323. Maximum 69 Number
// Difficulty : Easy
// Tags       : math, greedy
// Solved on  : 2020-01-20
// LeetCode   : https://leetcode.com/problems/maximum-69-number/

class Solution {
public:
    int maximum69Number (int num) {
        int n=0;
        vector<int> v;
        while(num){
            v.push_back(num%10);
            num=num/10;
        }
        //reverse(v.begin(),v.end());
        bool ok=false;
        int i=1;
        for(int j=v.size()-1;j>=0;j--){
            if(v[j]==6){
                v[j]=9;
                break;
            }
        }
        for(int a:v){
           n+=a*i;
           i*=10;
        }
        return n;
    }
};