// 0001. Two Sum
// Difficulty : Easy
// Tags       : array, hash-table
// Solved on  : 2022-06-09
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/two-sum/

class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        for($i =0 ; $i < count($nums) ; $i++)
        {
            for($j = 0 ; $j < $i ; $j++)
            {
                if($target-$nums[$i]==$nums[$j]) return [$j,$i];
            }
        }
    }
}