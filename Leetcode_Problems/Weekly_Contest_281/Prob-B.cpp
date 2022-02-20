#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* new_head = NULL;
        ListNode* cur = head->next;
        ListNode* new_cur = NULL;
        while(cur) {
            int sum = 0;
            while(cur->val) {
                sum += cur->val;
                cur = cur->next;
            }
            
            ListNode* node = new ListNode(sum);
            if(!new_head) {
                new_head = node;
                new_cur = node;
            }
            else {
                new_cur->next = node;
                new_cur = node;
            }
            cur = cur->next;
        }
        
        return new_head;
    }
};