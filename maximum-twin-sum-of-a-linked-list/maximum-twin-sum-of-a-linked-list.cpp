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
    int pairSum(ListNode* head) {
        stack<int> st;
        ListNode* fast = head;      
        ListNode* slow = head;      
        
        while(fast != NULL && fast->next != NULL){
            st.push(slow->val);
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* prv = NULL;
        ListNode* tmp;
        while(slow != NULL){
            tmp = slow->next;
            slow->next = prv;
            prv = slow;
            slow = tmp;
        } 
        slow = head;
        int ans = 0;
        while(prv != NULL){
            ans = max(ans, (slow->val + prv->val));
            slow = slow->next;
            prv = prv->next;
        }
        return ans;
    
    }
};