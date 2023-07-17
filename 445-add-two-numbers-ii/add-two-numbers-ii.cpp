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
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        while(head != NULL){
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }
    ListNode* addLists(ListNode* l1, ListNode* l2, int carry){
        if((l1 == NULL) && (l2 == NULL)){
            if(carry == 0) return NULL;

            ListNode* temp = new ListNode(carry%10);
            temp->next = addLists(l1, l2, carry/10);
            return temp;
        }
        else if(l1 == NULL){
            l2->val = l2->val + carry;
            l2->next = addLists(l1, l2->next, (l2->val)/10);
            l2->val = (l2->val)%10;
            return l2;
        }
        else if(l2 == NULL){
            l1->val = l1->val + carry;
            l1->next = addLists(l1->next, l2, (l1->val)/10);
            l1->val = (l1->val)%10;
            return l1;
        }
        
        l1->val = l1->val + l2->val + carry;
        l1->next = addLists(l1->next, l2->next, (l1->val)/10);
        l1->val = (l1->val)%10;
        return l1;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_new = reverseList(l1);
        ListNode* l2_new = reverseList(l2);

        ListNode* ans = addLists(l1_new, l2_new, 0);
        return reverseList(ans);
    }
};