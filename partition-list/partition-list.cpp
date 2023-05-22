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
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur = head;
        ListNode* left_head = NULL;
        ListNode* left_tail = NULL;
        ListNode* right_head = NULL;
        ListNode* right_tail = NULL;
        
        while(cur != NULL){
            if(cur->val < x){
                if(left_head == NULL){
                    left_head = cur;
                    left_tail = cur;
                }
                else{
                    left_tail->next = cur;
                    left_tail = left_tail->next;
                }
            }
            else{
                if(right_head == NULL){
                    right_head = cur;
                    right_tail = cur;
                }
                else{
                    right_tail->next = cur;
                    right_tail = right_tail->next;
                }
            }
            cur = cur->next;
        }
        if(left_head == NULL) return right_head;
        left_tail->next = right_head;
        if(right_head != NULL) right_tail->next = NULL;
        return left_head;
    }
};