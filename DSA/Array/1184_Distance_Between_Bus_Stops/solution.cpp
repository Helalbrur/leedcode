// 1184. Distance Between Bus Stops
// Difficulty : Easy
// Tags       : array
// Solved on  : 2019-09-08
// LeetCode   : https://leetcode.com/problems/distance-between-bus-stops/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int n=distance.size();
        long long int s=0,c=0;
        if(start<destination){
            for(int i=start;i<destination;i++){
                s+=distance[i];
            }
            if(start>0){
                for(int i=start-1;i>=0;i--){
                        c+=distance[i];
                }
            }

            for(int i=n-1;i>=destination;i--){
                 c+=distance[i];

            }

            return min(c,s);
        }else{
            c=0,s=0;
            for(int i=destination;i<start;i++){
                
                s+=distance[i];

            }
            for(int i=0;i<destination;i++){
                c+=distance[i];
            }
            for(int i=start;i<n;i++){
                c+=distance[i];
            }
            cout<<c<<" "<<s<<endl;
            return min(c,s);
            
        }
    }
};