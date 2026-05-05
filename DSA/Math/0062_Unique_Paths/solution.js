// 0062. Unique Paths
// Difficulty : Medium
// Tags       : math, dynamic-programming, combinatorics
// Solved on  : 2026-04-30
// LeetCode   : https://leetcode.com/problems/unique-paths/

/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    const dp = Array.from({length : m} , () => Array(n).fill(-1));
    const dfs = (i,j) => {
        if (i >=m || j >=n ) return 0;
        if (i == m -1 && j == n-1) return 1;
        if (dp[i][j] !=-1) return dp[i][j];
        return dp[i][j] = dfs(i+1,j) + dfs(i,j+1);
    }
    return dfs(0,0);
};