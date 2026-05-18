// 0049. Group Anagrams
// Difficulty : Medium
// Tags       : array, hash-table, string, sorting
// Solved on  : 2026-05-18
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/group-anagrams/

class Solution {

    /**
     * @param String[] $strs
     * @return String[][]
     */
    function groupAnagrams($strs) {
        $map = [];
        foreach($strs as $str){
            $count = array_fill(0,26,0);
            for($i = 0; $i < strlen($str);$i++){
                $ch = $str[$i];
                $ascii = ord($ch) - ord('a');
                $count[$ascii]++;
            }
            $key = implode("#",$count);
            if (!isset($map[$key])){
                $map[$key] = [];
            }
            array_push($map[$key],$str);
        }
        #var_dump($map);
        $res = [];
        foreach($map as $key => $val){
            array_push($res,$val);
        }
        return $res;
    }
}