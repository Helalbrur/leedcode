// 0303. Range Sum Query - Immutable
// Difficulty : Easy
// Tags       : array, design, prefix-sum
// Solved on  : 2019-07-23
// LeetCode   : https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    vector<int> vec; 
    NumArray(vector<int>& nums) {
        vec.clear();
        for(int i=0;i<nums.size();i++){
            vec.push_back(nums[i]);
        }
    }
    
    int sumRange(int i, int j) {
       
        if(i==j){
            return vec[i];
        }else if(i>j){
            return 0;
        }
        return sumRange(i+1,j)+vec[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */