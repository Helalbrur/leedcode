// 3110. Score of a String
// Difficulty : Easy
// Tags       : string
// Solved on  : 2025-10-20
// LeetCode   : https://leetcode.com/problems/score-of-a-string/

class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function scoreOfString($s) {
        $score = 0;
        for($i = 0; $i < strlen($s) - 1; $i++)
        {
            $score += abs(ord($s[$i]) - ord($s[$i+1]));
        }
        return $score ;
    }
}