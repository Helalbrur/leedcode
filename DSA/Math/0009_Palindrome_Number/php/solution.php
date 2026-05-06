// 0009. Palindrome Number
// Difficulty : Easy
// Tags       : math
// Solved on  : 2022-06-09
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/palindrome-number/

class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        $y=strrev($x);
        if($x==$y) return true;
        return false;
    }
}