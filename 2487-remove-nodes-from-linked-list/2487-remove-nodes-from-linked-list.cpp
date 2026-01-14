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
    ListNode* removeNodes(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

        int maxi = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        curr = head;
        while(curr != NULL) {
            if(curr->val >= maxi) {
                maxi = curr->val;
                tail->next = curr;
                tail = tail->next;
            }
            curr = curr->next;
        }
        tail->next = NULL;
        prev = NULL;
        curr = dummy->next;

          while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};