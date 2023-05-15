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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1 = head;
        ListNode* n2 = head;

        ListNode* temp = head;
        for(int i=0; i<k; ++i) temp = temp->next;
        for(int i=1; i<k; ++i) n1 = n1->next;

        while(temp != NULL){
            temp = temp->next;
            n2 = n2->next;
        }

        if(n1 == n2) return head;
        int tp = n1->val;
        n1->val = n2->val;
        n2->val = tp;
        
        return head;
    }
};