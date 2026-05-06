// 0120. Triangle
// Difficulty : Medium
// Tags       : array, dynamic-programming
// Solved on  : 2026-05-05
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/triangle/

class Solution {
    private $dp,$mx = ((1 << 32) -1);
    public function __construct(){
        for($i = 0; $i <=202; $i ++){
            $this->dp[$i] = array_fill(0,$i+1,$this->mx);
        }
    }
    /**
     * @param Integer[][] $triangle
     * @return Integer
     */
    function minimumTotal($triangle) {
        $this->m = count($triangle);
        return $this->minT(0,0,$triangle);
    }

    private function minT($i,$j,$triangle){
        
        if ($i >=$this->m ){
            return $this->mx;
        }
        $n = count($triangle[$i]);
        if ($j >= $n ) return $this->mx;
        if ($i == $this->m -1 ){
            return $triangle[$i][$j];
        }
        if ($this->dp[$i][$j] != $this->mx){
            return $this->dp[$i][$j];
        }
        return $this->dp[$i][$j] = min($this->minT($i+1,$j,$triangle),$this->minT($i+1,$j+1,$triangle)) + $triangle[$i][$j];
    }
}