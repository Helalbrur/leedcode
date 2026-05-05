// 0461. Hamming Distance
// Difficulty : Easy
// Tags       : bit-manipulation
// Solved on  : 2020-02-23
// LeetCode   : https://leetcode.com/problems/hamming-distance/

class Solution {
public:
    int hammingDistance(int x, int y) {
        string a,b;
        while (x){
            
            a+=x%2+'0';
            x/=2;
            }
        while(y){
            b+=y%2+'0';
            y/=2;
            }
        int i=0;
        int cnt=0;
        for(i=0;i<min(a.length(),b.length());i++){
            if(a[i]!=b[i]) cnt++;
            }
        for(;i<a.length();i++){
            if(a[i]=='1') cnt++;
            }
        for(;i<b.length();i++){
            if(b[i]=='1') cnt++;
            }
        return cnt;
    }
};