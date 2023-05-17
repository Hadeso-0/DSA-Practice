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

        int ans = 0;
        while(slow != NULL){
            ans = max(ans, (slow->val + st.top()));
            st.pop();
            slow = slow->next;
        }
        return ans;
    }
};