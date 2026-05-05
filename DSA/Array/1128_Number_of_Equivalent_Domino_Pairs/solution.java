// 1128. Number of Equivalent Domino Pairs
// Difficulty : Easy
// Tags       : array, hash-table, counting
// Solved on  : 2019-08-22
// LeetCode   : https://leetcode.com/problems/number-of-equivalent-domino-pairs/

class Solution {
    public int numEquivDominoPairs(int[][] dominoes) {
        HashMap<String, Integer> map = new HashMap<>();
		String temp;
		int result = 0;
		for (int[] dominoe : dominoes) {
			int sum = dominoe[0] + dominoe[1];
			int sub = Math.abs(dominoe[0] - dominoe[1]);
			temp = sum + "," + sub;
			int gt = map.getOrDefault(temp, 0) + 1;
			result += (gt - 1);
			map.put(temp, gt);
		}

		return result;
    }
}