// 1185. Day of the Week
// Difficulty : Easy
// Tags       : math
// Solved on  : 2019-10-28
// LeetCode   : https://leetcode.com/problems/day-of-the-week/

class Solution {

    /**
     * @param Integer $day
     * @param Integer $month
     * @param Integer $year
     * @return String
     */
    function dayOfTheWeek($day, $month, $year) {
        $timestamp = strtotime($year.'-'.$month.'-'.$day);
        return date('l', $timestamp);
    }
}