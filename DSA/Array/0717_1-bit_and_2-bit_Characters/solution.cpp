// 0717. 1-bit and 2-bit Characters
// Difficulty : Easy
// Tags       : array
// Solved on  : 2022-05-31
// LeetCode   : https://leetcode.com/problems/1-bit-and-2-bit-characters/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len=bits.size();
        int two=0;
        for(int i=0;i<len;i++)
        {
            if(bits[i]==1)
            {
                if(two==1)
                {
                    two=0;
                }
                else{
                   two=1; 
                }
                
            }
            else if(two==1 && i==len-1 )
            {
                two=1;
            }
            else{
                two=0;
            }
        }
        return two==0;
        
        
    }
};