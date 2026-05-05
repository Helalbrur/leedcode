// 0063. Unique Paths II
// Difficulty : Medium
// Tags       : array, dynamic-programming, matrix
// Solved on  : 2026-05-03
// LeetCode   : https://leetcode.com/problems/unique-paths-ii/

function uniquePathsWithObstacles(obstacleGrid: number[][]): number {
    const m = obstacleGrid.length;
    const n = obstacleGrid[0].length;
    const dp = Array.from({length:m},()=> Array(n).fill(-1));
    
    const dfs = (i,j) => {
        if (i >=m || j >=n) return 0;
        if (obstacleGrid[i][j] == 1) return 0;
        if ((i == m-1) && (j == n-1)) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = dfs(i+1,j) + dfs(i,j+1);
        
    }
    return dfs(0,0);
};