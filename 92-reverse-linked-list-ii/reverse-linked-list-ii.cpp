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
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(head != NULL){
            cur = head->next;
            head->next = pre;
            pre  = head;
            head = cur;
        }
        return pre;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return head;

        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        while(ptr2!=NULL && --right){ ptr2 = ptr2->next;}
        
        --left;
        while(ptr1!=NULL && (--left)>0){ ptr1 = ptr1->next;}
        // cout<<left;
        // return head;
        ListNode* temp2 = ptr2->next;
        ptr2->next = NULL;

        if(left == -1){
            head = revList(ptr1);
        }
        else{
            ptr1->next = revList(ptr1->next);
        }
        while(ptr1->next != NULL) ptr1 = ptr1->next;
        
        ptr1->next = temp2;
        return head;
    }
};