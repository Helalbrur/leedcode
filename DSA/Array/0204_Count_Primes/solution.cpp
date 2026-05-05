// 0204. Count Primes
// Difficulty : Medium
// Tags       : array, math, enumeration, number-theory
// Solved on  : 2019-08-10
// LeetCode   : https://leetcode.com/problems/count-primes/

class Solution {
public:
    bool prime[10000010];
    int countPrimes(int n) {
        memset(prime,0,sizeof(prime));
        isPrime(n);
        int cnt=0;
        for(int i=2;i<n;i++){
            if(prime[i]==0){
               // cout<<i<<" ";
                cnt++;
            }
        }
       // cout<<endl;
        return cnt;
    }
    void isPrime(int n){
        for(int i=4;i<=n;i+=2){
            prime[i]=1;
        }
        int sq=sqrt(n+2);
        for(int i=3;i<=sq;i+=2){
            if(prime[i]==0){
                for(int j=i+i;j<=n;j+=i){
                    prime[j]=1;
                }
            }
        }
        return;
    }
    
};