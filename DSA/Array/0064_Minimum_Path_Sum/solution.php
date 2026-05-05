// 0064. Minimum Path Sum
// Difficulty : Medium
// Tags       : array, dynamic-programming, matrix
// Solved on  : 2026-05-04
// LeetCode   : https://leetcode.com/problems/minimum-path-sum/

class Solution {
    private $dp,$mx = 1000000000,$m,$n;
    public function __construct(){
        for($i = 0; $i <=201;$i++){
            $this->dp[$i] = array_fill(0,201,$this->mx);
        }
    }
    /**
     * @param Integer[][] $grid
     * @return Integer
     */
    function minPathSum($grid) {
        $this->m = count($grid);
        $this->n = count($grid[0]);
        return $this->minPath(0,0,$grid);
    }

    private function minPath($i,$j,$grid){
        if ($i >= $this->m || $j >= $this->n) return $this->mx;
        if ($i == $this->m -1 && $j == $this->n -1 ) return $grid[$i][$j];
        if ($this->dp[$i][$j]!=$this->mx) return $this->dp[$i][$j];
        return $this->dp[$i][$j] = min($this->minPath($i+1,$j,$grid),$this->minPath($i,$j+1,$grid)) + $grid[$i][$j];
    }
}