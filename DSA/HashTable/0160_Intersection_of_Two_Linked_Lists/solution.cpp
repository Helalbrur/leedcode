// 0160. Intersection of Two Linked Lists
// Difficulty : Easy
// Tags       : hash-table, linked-list, two-pointers
// Solved on  : 2019-08-24
// LeetCode   : https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*,int> mp;
        while(headA){
            mp[headA]++;
            headA=headA->next;
            
        }
         while(headB){
            mp[headB]++;
            headB=headB->next;
            
        }
        for(auto it=mp.begin();it!=mp.end();++it){
            if(it->second==2){
                return it->first;
            }
        }
        return NULL;
    }
};