// 0009. Palindrome Number
// Difficulty : Easy
// Tags       : math
// Solved on  : 2026-04-21
// LeetCode   : https://leetcode.com/problems/palindrome-number/

class Solution {

    /**
     * @param Integer $x
     * @return Boolean
     */
    function isPalindrome($x) {
        if ($x < 0 || ($x % 10 == 0 && $x != 0)) return false;
        if ($x == 0) return true;
        $half_number = 0;
        while($x > $half_number){
            $half_number = $half_number * 10 + ($x % 10);
            $x = (int) ($x / 10);
            if ($half_number == $x || (int)($half_number / 10) == $x) return true;
        }
        return false;
    }
}