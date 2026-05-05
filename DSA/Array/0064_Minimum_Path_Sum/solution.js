// 0064. Minimum Path Sum
// Difficulty : Medium
// Tags       : array, dynamic-programming, matrix
// Solved on  : 2026-05-04
// LeetCode   : https://leetcode.com/problems/minimum-path-sum/

/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    const mx = 100000000;
    const dp = Array.from({length:m},()=>Array(n).fill(mx));
    const minPath = (i,j)=>{
        if ( i >=m || j >= n) return mx;
        if ( i == m -1 && j == n - 1) return grid[i][j];
        if (dp[i][j] != mx) return dp[i][j];
        return dp[i][j] = Math.min(minPath(i+1,j),minPath(i,j+1)) + grid[i][j];
    }
    return minPath(0,0);
};