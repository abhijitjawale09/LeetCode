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
    ListNode* mergetwolists(ListNode* l1 , ListNode* l2) {
        if(!l1) {
            return l2;
        }
        if(!l2) {
            return l1;
        }

        if(l1->val <= l2->val) {
            l1->next = mergetwolists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergetwolists(l1 , l2->next);
            return l2;
        }
        return NULL;
    }
    ListNode* partitionAndmerge(int start , int end , vector<ListNode*>& lists) {
        if(start == end) {
            return lists[start];
        }
        if(start > end) {
            return NULL;
        }
        int mid = start + (end - start) / 2;

        ListNode* l1 = partitionAndmerge(start , mid , lists);
        ListNode* l2 = partitionAndmerge(mid + 1 , end , lists);

        return mergetwolists(l1 , l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) {
            return NULL;
        }
        if(n == 1) {
            return lists[0];
        }
        
        return partitionAndmerge(0 , n - 1, lists);
    }
};