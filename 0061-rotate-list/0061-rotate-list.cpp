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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) {
            return head;
        }

        int n = 1;
        ListNode* temp = head;
        while(temp->next) {
            temp = temp->next;
            n++;
        }
        temp->next = head;
        k = k % n;

        int nexthead = n - k;
        temp = head;
        for(int i = 1; i < nexthead ; i++) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};

// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         if (!head || !head->next || k == 0) return head;
//         int n = 1;
        
//         ListNode* temp = head;
//         while (temp->next) {
//             temp = temp->next;
//             n++;
//         }
//         temp->next = head;
//         k = k % n;
//         int stepsToNewHead = n - k;
//         temp = head;
//         for (int i = 1; i < stepsToNewHead; i++) {
//             temp = temp->next;
//         }
//         ListNode* newHead = temp->next;
//         temp->next = NULL;
//         return newHead;
//     }
// };
