// 1154. Day of the Year
// Difficulty : Easy
// Tags       : math, string
// Solved on  : 2019-08-19
// LeetCode   : https://leetcode.com/problems/day-of-the-year/

class Solution {
public:
    int dayOfYear(string date) {
        int day=(date[8]-'0')*10+date[9]-'0';
        int month=(date[5]-'0')*10+date[6]-'0';
        int year=(date[0]-'0')*1000+(date[1]-'0')*100+(date[2]-'0')*10+(date[3]-'0');
        
        int flag=0;
      
        if(year%400==0){
            flag=1;
        }else if(year%4==0 && year%100!=0){
            flag=1;
        }
        
        int cnt=0;
        int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(flag==1){
            a[2]++;
        }
        for(int i=1;i<month;i++){
            cnt+=a[i];
           
        }
        cnt+=day;
        
        //cout<<cnt<<endl;
        //cout<<year<<" "<<flag<<" "<<month<<" "<<day<<endl;
        
        return cnt;
    }
};