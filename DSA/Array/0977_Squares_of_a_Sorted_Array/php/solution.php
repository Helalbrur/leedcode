// 0977. Squares of a Sorted Array
// Difficulty : Easy
// Tags       : array, two-pointers, sorting
// Solved on  : 2026-05-14
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function sortedSquares($nums) {
        $nums = array_map(fn($n) => $n * $n,$nums);
        sort($nums);
        return $nums;
    }
}