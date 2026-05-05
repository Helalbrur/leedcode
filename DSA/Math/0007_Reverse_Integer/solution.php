// 0007. Reverse Integer
// Difficulty : Medium
// Tags       : math
// Solved on  : 2026-04-20
// LeetCode   : https://leetcode.com/problems/reverse-integer/

class Solution {

    /**
     * @param Integer $x
     * @return Integer
     */
    function reverse($x) {
        $sign = $x < 0 ? -1 : 1;
        $num = (int) strrev((string)abs($x));
        $INT_MAX = (1 << 31) - 1;
        return $num > $INT_MAX ? 0 : $sign * $num;
    }
}