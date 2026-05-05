// 0062. Unique Paths
// Difficulty : Medium
// Tags       : math, dynamic-programming, combinatorics
// Solved on  : 2026-04-30
// LeetCode   : https://leetcode.com/problems/unique-paths/

class Solution {
    private $dp = [];
    public function __construct(){
        for($i = 0; $i <101; $i++){
            $this->dp[$i] = array_fill(0,101,-1);
        }
    }
    /**
     * @param Integer $m
     * @param Integer $n
     * @return Integer
     */
    function uniquePaths($m, $n) {
        return $this->dfs(0,0,$m,$n);
    }

    private function dfs($i,$j,$m,$n){
        if ($i >=$m || $j >=$n) return 0;
        if (($i == $m -1) && ($j == $n -1)) return 1;
        if ( $this->dp[$i][$j] != -1) return $this->dp[$i][$j];
        return $this->dp[$i][$j] = $this->dfs($i+1,$j,$m,$n) + $this->dfs($i,$j+1,$m,$n);
    }
}