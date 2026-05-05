// 0929. Unique Email Addresses
// Difficulty : Easy
// Tags       : array, hash-table, string
// Solved on  : 2019-08-04
// LeetCode   : https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string,int> mp;
        for(int i=0;i<emails.size();i++){
            string a;
          
            int pl=0;
            for(int j=0;j<emails[i].length();j++){
                if(emails[i][j]=='+'){
                    pl=1;
                  
                }else if(emails[i][j]=='@' ){
                    
                     pl=2;
                    a+='@';
                }
               
               
               else if(pl==0 && emails[i][j]!='.'){
                    a+=emails[i][j];
                }else if(pl==2){
                   a+=emails[i][j];
               }
               
            }
           
          // cout<<a<<endl;
            mp[a]++;
        }
       return mp.size();
    }
};