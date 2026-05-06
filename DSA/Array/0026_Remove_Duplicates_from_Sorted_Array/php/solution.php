// 0026. Remove Duplicates from Sorted Array
// Difficulty : Easy
// Tags       : array, two-pointers
// Solved on  : 2022-06-14
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/remove-duplicates-from-sorted-array/

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        
        $arr=array();
        foreach($nums as $num)
        {
            if(!in_array($num,$arr))
            {
                array_push($arr,$num);
            }
        }
        $nums=$arr;
        return count($nums);
    }
}