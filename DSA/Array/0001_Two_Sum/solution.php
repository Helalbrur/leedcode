// 0001. Two Sum
// Difficulty : Easy
// Tags       : array, hash-table
// Solved on  : 2026-04-19
// LeetCode   : https://leetcode.com/problems/two-sum/

class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $taken = [];
        foreach($nums as $indx=>$val){
            $sub = $target - $val;
            if(array_key_exists($sub,$taken)){
                return [$taken[$sub],$indx];
            }
            $taken[$val] = $indx;
        }
    }
}