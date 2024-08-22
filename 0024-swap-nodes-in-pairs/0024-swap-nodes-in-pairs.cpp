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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next ) {
            return head;
        }
        ListNode* dummy = new ListNode();


        ListNode* slow = dummy;
        ListNode* fast = head;


        while(fast && fast->next) {

            slow->next = fast->next;
            fast->next = slow->next->next;
            slow->next->next = fast;

            slow = fast;
            fast = fast->next;

        }
        return dummy->next;
    }
};