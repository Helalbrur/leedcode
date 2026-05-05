// 0063. Unique Paths II
// Difficulty : Medium
// Tags       : array, dynamic-programming, matrix
// Solved on  : 2026-05-03
// LeetCode   : https://leetcode.com/problems/unique-paths-ii/

class Solution {

    private $dp = [];

    function __construct(){
        for($i = 0; $i <=101;$i++){
            $this->dp[$i] = array_fill(0,101,-1);
        }
    }
    /**
     * @param Integer[][] $obstacleGrid
     * @return Integer
     */
    function uniquePathsWithObstacles($obstacleGrid) {
        $m = count($obstacleGrid);
        $n = count($obstacleGrid[0]);
        return $this->dfs(0,0,$obstacleGrid,$m,$n);
    }

    private function dfs($i,$j,$grid,$m,$n){
        if ($i >= $m || $j >= $n) return 0;
        if ($grid[$i][$j] == 1) return 0;
        if ($i == $m - 1 && $j == $n -1 ) return 1;
        if ($this->dp[$i][$j] != -1 ) return $this->dp[$i][$j];
        return $this->dp[$i][$j] = $this->dfs($i+1,$j,$grid,$m,$n) + $this->dfs($i,$j+1,$grid,$m,$n);
    }
}