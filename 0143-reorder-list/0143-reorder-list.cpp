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
    void reorderList(ListNode* head) {
       ListNode* slow = head;
    ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }   

        ListNode* curr = slow;
        slow->next = NULL;   
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* first = head;
        ListNode* second = prev;
        while(second != NULL) {
            ListNode* t1 = first->next;
            ListNode* t2 = second->next;

            first->next  = second;
            second->next = first;


            first = t1;
            second = t2;

        }

    }
};