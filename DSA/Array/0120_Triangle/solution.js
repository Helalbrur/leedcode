// 0120. Triangle
// Difficulty : Medium
// Tags       : array, dynamic-programming
// Solved on  : 2026-05-05
// LeetCode   : https://leetcode.com/problems/triangle/

/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    const mx = Math.abs((1 <<31) - 1);
    const m = triangle.length;
    const dp = Array.from({length:m},()=>Array(m).fill(mx));
    const minT = (i,j) => {
        const n = triangle[i].length;
        if ( i >= m || j >= n) return mx;
        if (i == m -1) return triangle[i][j];
        if (dp[i][j] !=mx) return dp[i][j];
        return dp[i][j] = Math.min(minT(i+1,j),minT(i+1,j+1)) + triangle[i][j];
    }
    return minT(0,0);
};