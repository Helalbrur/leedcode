// 2942. Find Words Containing Character
// Difficulty : Easy
// Tags       : array, string
// Solved on  : 2025-10-20
// LeetCode   : https://leetcode.com/problems/find-words-containing-character/

class Solution {

    /**
     * @param String[] $words
     * @param String $x
     * @return Integer[]
     */
    function findWordsContaining($words, $x) {
        $res = [];
        foreach ($words as $i => $word) {
            if (strpos($word, $x) !== false) {
                $res[] = $i;
            }
        }
        return $res;
    }
}