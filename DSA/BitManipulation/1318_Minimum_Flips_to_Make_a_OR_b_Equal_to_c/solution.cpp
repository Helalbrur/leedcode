// 1318. Minimum Flips to Make a OR b Equal to c
// Difficulty : Medium
// Tags       : bit-manipulation
// Solved on  : 2020-01-13
// LeetCode   : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        string p_a=bits(a);
        string p_b=bits(b);
        string p_c=bits(c);
        int l_a=p_a.length();
        int l_b=p_b.length();
        int l_c=p_c.length();
        int mx=max(l_a,max(l_b,l_c));
        if(l_a<mx){
            string temp;
            for(int i=1;i<=mx-l_a;i++){
                temp+='0';
            }
            p_a=temp+p_a;
        }
        if(l_b<mx){
            string temp;
            for(int i=1;i<=mx-l_b;i++){
                temp+='0';
            }
            p_b=temp+p_b;
        }
        if(l_c<mx){
            string temp;
            for(int i=1;i<=mx-l_c;i++){
                temp+='0';
            }
            p_c=temp+p_c;
        }
        cout<<p_a<<endl<<p_b<<endl<<p_c<<endl;
        int cnt=0;
        for(int i=0;i<mx;i++){
            if(p_c[i]=='0'){
                if(p_a[i]=='1'){
                    cnt++;
                }
                if(p_b[i]=='1'){
                    cnt++;
                }
            }else{
                if(p_a[i]=='1' || p_b[i]=='1'){
                    continue;
                }else{
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
    
     string bits(int n){
        string s="";
       
        while(n){
            int r=n%2;
            s+=r+'0';
            n=n/2;
        }
        
        string b;
         for(int i=s.length()-1;i>=0;i--){
             b+=s[i];
         }
         return b;
    }
};