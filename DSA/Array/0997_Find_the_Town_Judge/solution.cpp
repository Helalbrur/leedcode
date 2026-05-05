// 0997. Find the Town Judge
// Difficulty : Easy
// Tags       : array, hash-table, graph
// Solved on  : 2023-01-23
// LeetCode   : https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> i_trust_people[n+100];
        vector<int> people_trust_me[n+100];
        for(int i = 0; i<trust.size();i++)
        {
            int x = trust[i][0];
            int y = trust[i][1];
            i_trust_people[x].push_back(y);
            people_trust_me[y].push_back(x);
        }
        for(int i = 1;i<=n;i++)
        {
            if(people_trust_me[i].size() == n-1)
            {
                if(i_trust_people[i].size() <=0)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};