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
        vector<int> vec;
        ListNode* temp = head;
        while(temp != NULL) {
            vec.push_back(temp->val);
            temp = temp->next;
        }

        int n = vec.size();
        int j = n-1;
        int i = 0;
        int maxsum = INT_MIN;
        while(i < j) {
            maxsum = max(maxsum , vec[i] + vec[j]);
            i++;
            j--;
        }
        return maxsum;
    }
};