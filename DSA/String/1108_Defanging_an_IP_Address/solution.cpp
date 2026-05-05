// 1108. Defanging an IP Address
// Difficulty : Easy
// Tags       : string
// Solved on  : 2019-07-26
// LeetCode   : https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
public:
    string defangIPaddr(string address) {
        string a;
        for(int i=0;i<address.length();i++){
            if(address[i]=='.'){
                a+="[.]";
                
            }else{
                a+=address[i];
            }
        }
        return a;
    }
};