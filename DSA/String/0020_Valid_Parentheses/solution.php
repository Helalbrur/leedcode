// 0020. Valid Parentheses
// Difficulty : Easy
// Tags       : string, stack
// Solved on  : 2026-04-23
// LeetCode   : https://leetcode.com/problems/valid-parentheses/

class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isValid($s) {
        $stack = [];
        $blance_arr = [')' => '(','}' => '{' , ']' => '['];
        for ($i = 0; $i <strlen($s);$i++){
            if(isset($blance_arr[$s[$i]])){
                if(empty($stack) || array_pop($stack) != $blance_arr[$s[$i]]) return false;
            }
            else{
                $stack[] =$s[$i];
            }
        }
        return count($stack) == 0;
    }
}