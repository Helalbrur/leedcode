// 0657. Robot Return to Origin
// Difficulty : Easy
// Tags       : string, simulation
// Solved on  : 2019-07-26
// Attempt    : #2
// LeetCode   : https://leetcode.com/problems/robot-return-to-origin/

class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='U'){
                y++;
            }else if(moves[i]=='D'){
                y--;
            }else if(moves[i]=='L'){
                x--;
            }else if(moves[i]=='R'){
                x++;
            }
        }
        if(x==0 && y==0){
            return true;
        }else{
            return false;
        }
    }
};