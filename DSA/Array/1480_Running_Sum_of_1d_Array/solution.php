// 1480. Running Sum of 1d Array
// Difficulty : Easy
// Tags       : array, prefix-sum
// Solved on  : 2022-07-07
// LeetCode   : https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function runningSum($nums) {
        $sum = 0;
        for ( $i =0 ; $i < count($nums) ; $i++)
        {
            $sum += $nums[$i];
            $nums[$i] = $sum;
        }
        return $nums;
    }
}