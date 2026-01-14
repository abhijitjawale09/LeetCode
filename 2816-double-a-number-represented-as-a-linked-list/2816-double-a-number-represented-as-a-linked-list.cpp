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
    ListNode* doubleIt(ListNode* head) {
        if (head == NULL) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        curr = head;
        int carry = 0;
        while(curr != NULL) {
            int num = curr->val * 2 + carry;
            curr->val = num % 10;
            carry = num / 10;

            if(curr->next == NULL && carry > 0) {
                curr->next = new ListNode(carry);
                break;
            }
            curr = curr->next;
        }

        curr = head;
        prev = NULL;
        next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }  
};