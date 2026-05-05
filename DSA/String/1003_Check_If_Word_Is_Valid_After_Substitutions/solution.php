// 1003. Check If Word Is Valid After Substitutions
// Difficulty : Medium
// Tags       : string, stack
// Solved on  : 2021-02-12
// LeetCode   : https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $sub=str_replace("abc","",$s);
        while(strlen($sub) < strlen($s))
        {
            $s=$sub;
            $sub=str_replace("abc","",$s);
        }
        return strlen($s)==0;
    }
}