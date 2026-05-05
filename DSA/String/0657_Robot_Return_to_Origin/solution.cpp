// 0657. Robot Return to Origin
// Difficulty : Easy
// Tags       : string, simulation
// Solved on  : 2020-02-03
// LeetCode   : https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(char c:moves){
            if(c=='U'){
                y++;
            }else if(c=='D'){
                y--;
            }else if(c=='L'){
                x--;
            }else if(c=='R'){
                x++;
            }
        }
        if(x==0 && y==0) return true;
        return false;
    }
};