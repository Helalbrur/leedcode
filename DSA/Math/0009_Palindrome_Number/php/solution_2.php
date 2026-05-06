// 0009. Palindrome Number
// Difficulty : Easy
// Tags       : math
// Solved on  : 2026-04-21
// Attempt    : #2
// LeetCode   : https://leetcode.com/problems/palindrome-number/

class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        return $x >= 0 && (string)$x == strrev((string)$x);
    }
}