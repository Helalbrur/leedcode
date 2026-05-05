// 1324. Print Words Vertically
// Difficulty : Medium
// Tags       : array, string, simulation
// Solved on  : 2020-01-20
// LeetCode   : https://leetcode.com/problems/print-words-vertically/

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> word;
        string w;
        int mx=INT_MIN;
        int i=0;
        for(char c: s){
            if(isAlpha(c)){
                w+=c;
                if(i==s.length()-1){
                    word.push_back(w);
                     int len=w.length();
                     mx=max(mx,len);
                }
            }else{
                word.push_back(w);
                int len=w.length();
                mx=max(mx,len);
                w="";
            }
            i++;
        }
        int row=word.size();
        int col=mx;
        vector<string> result;
        w="";
       
            
            for(int j=0;j<col;j++){
                
                 for(int i=0;i<row;i++){
                    if(j<word[i].size()){
                        w+=word[i][j];
                    }else{
                        w+=' ';
                    }
                 }
                while(w[w.length()-1]==' '){
                    w.pop_back();
                }
                result.push_back(w);
                w="";
            }
            
       
       
       return result; 
        
        
    }
    bool isAlpha(char c){
        if(c>='a' && c<='z' ){
            return true;
        }
        if(c>='A' && c<='Z' ){
            return true;
        }
        return false;
    }
};