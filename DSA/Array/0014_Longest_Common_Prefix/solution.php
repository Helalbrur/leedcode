// 0014. Longest Common Prefix
// Difficulty : Easy
// Tags       : array, string, trie
// Solved on  : 2023-01-07
// LeetCode   : https://leetcode.com/problems/longest-common-prefix/

class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        $min_len = 1000;
        for($i = 0 ; $i < count($strs); $i++)
        {
            $min_len = min($min_len,strlen($strs[$i]));
        }
        $result = substr($strs[0],0,$min_len);

        for($i = 0 ; $i < count($strs) ; $i++)
        {
            for($j = 0 ; $j < $min_len ; $j++)
            {
                if($strs[0][$j] != $strs[$i][$j])
                {
                    
                    if(strlen($result) > $j )
                    {
                        $temp = substr($strs[0],0,$j);
                        $result = $temp;
                    }
                }
            }
        }
        return $result;
    }
}