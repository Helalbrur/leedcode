// 0997. Find the Town Judge
// Difficulty : Easy
// Tags       : array, hash-table, graph
// Solved on  : 2020-02-03
// Attempt    : #2
// LeetCode   : https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int a[N+2][N+2];
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                a[i][j]=0;
            }
        }
        for(int i=0;i<trust.size();i++){
            int x=trust[i][0];
            int y=trust[i][1];
            a[x][y]=1;
        }
        int cnt=0;
        int p=0;
        for(int i=1;i<=N;i++){
            cnt=0;
            for(int j=1;j<=N;j++){
               cnt+= a[i][j];
            }
            if(cnt==0){
                p=i;
                break;
            }
        }
        if(p==0) return -1;
        for(int i=1;i<=N;i++){
            if(a[i][p]==0 && p!=i) return -1;
        }
        return p;
    }
};