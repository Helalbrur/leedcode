// 1025. Divisor Game
// Difficulty : Easy
// Tags       : math, dynamic-programming, brainteaser, game-theory
// Solved on  : 2019-10-11
// LeetCode   : https://leetcode.com/problems/divisor-game/

class Solution {
public:
    
    bool divisorGame(int N) {
        if(N%2==0)
            return true;
        return false;
    }
   
};