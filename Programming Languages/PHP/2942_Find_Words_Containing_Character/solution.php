// 2942. Find Words Containing Character
// Difficulty : Easy
// Tags       : array, string
// Solved on  : 2025-10-20
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/find-words-containing-character/

class Solution {

    /**
     * @param String[] $words
     * @param String $x
     * @return Integer[]
     */
    function findWordsContaining($words, $x) {
        $res = [];
        for($i = 0; $i < count($words) ; $i++)
        {
            for($j = 0; $j< strlen($words[$i]) ; $j++)
            {
                if($words[$i][$j] == $x){
                    array_push($res,$i);
                    break;
                }
            }
        }
        return $res;
    }
}