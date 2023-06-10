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
    ListNode* revList(ListNode* head){
        ListNode* prev = NULL;
        while(head!= NULL){
            ListNode* nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        return prev;
    }
    ListNode* merge(ListNode* h1, ListNode* h2){
        if(h1 == NULL) return h2;
        if(h2 == NULL) return h1;

        ListNode* nex = merge(h1->next, h2->next);
        h1->next = h2;
        h2->next = nex;
        return h1; 
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL) return; 
        if(head->next == NULL) return; 
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* h2 = revList(slow->next);
        slow->next = NULL;
        head = merge(head, h2);
    }
};