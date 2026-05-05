// 0026. Remove Duplicates from Sorted Array
// Difficulty : Easy
// Tags       : array, two-pointers
// Solved on  : 2026-04-28
// LeetCode   : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $nums = array_unique($nums);
        return count($nums);
    }
}