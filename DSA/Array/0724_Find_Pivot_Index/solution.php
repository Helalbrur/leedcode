// 0724. Find Pivot Index
// Difficulty : Easy
// Tags       : array, prefix-sum
// Solved on  : 2022-07-07
// LeetCode   : https://leetcode.com/problems/find-pivot-index/

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function pivotIndex($nums) {
        $sum = 0 ;
        for ( $i = 0 ; $i < count($nums) ; $i++)
        {
            $sum += $nums[$i];
        }
        $s = 0;
        for ( $i = 0 ; $i < count( $nums ) ; $i++)
        {
            if( $sum - $s - $nums[$i] == $s) return $i;
            $s += $nums[$i];
        }
        return -1;
    }
}