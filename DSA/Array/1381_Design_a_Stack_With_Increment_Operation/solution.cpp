// 1381. Design a Stack With Increment Operation
// Difficulty : Medium
// Tags       : array, stack, design
// Solved on  : 2020-03-15
// LeetCode   : https://leetcode.com/problems/design-a-stack-with-increment-operation/

class CustomStack {
public:
    int maxSize;
    int top=0;
    int a[1005];
    CustomStack(int maxSize) {
        if(maxSize<=1000){
            this->maxSize=maxSize;
        }
    }
    
    void push(int x) {
        if(top<maxSize){
            a[++top]=x;
        }
    }
    
    int pop() {
        if(top>0){
            return a[top--];
        }else return -1;
    }
    
    void increment(int k, int val) {
        
        for(int i=1;i<=k && i<=top;i++){
            a[i]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */