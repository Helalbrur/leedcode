// 1185. Day of the Week
// Difficulty : Easy
// Tags       : math
// Solved on  : 2019-09-08
// Attempt    : #1
// LeetCode   : https://leetcode.com/problems/day-of-the-week/

class Solution {

    /**
     * @param Integer $day
     * @param Integer $month
     * @param Integer $year
     * @return String
     */
    function dayOfTheWeek($day, $month, $year) {
        $date=$day.'-'.$month.'-'.$year;
        $d=date("l", strtotime($date));
        return $d;
    }
}