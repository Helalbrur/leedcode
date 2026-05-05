// 0788. Rotated Digits
// Difficulty : Medium
// Tags       : math, dynamic-programming
// Solved on  : 2019-07-20
// LeetCode   : https://leetcode.com/problems/rotated-digits/

class Solution {
public:
    int rotat[11];
    int rotatedDigits(int N) {
        
        for(int i=0;i<=9;i++){
            rotat[i]=i;
        }
        rotat[2]=5;
        rotat[5]=2;
        rotat[6]=9;
        rotat[9]=6;
        rotat[3]=-1;
        rotat[4]=-1;
        rotat[7]=-1;
        int cnt=0;
        for(int i=1;i<=N;i++){
            int r=rot(i);
            cnt+=r;
            //cout<<i<<" "<<r<<endl;
        }
        return cnt;
        
    }
    int rot(int a){
        int b=a;
        int i=1,result=0;
        while(a){
            int r=a%10;
            if(rotat[r]==-1){
                return 0;
            }
            result=rotat[r]*i+result;
            i=i*10;
            a=a/10;
        }
        if(b==result){
            return 0;
        }
        return 1;
    }
};