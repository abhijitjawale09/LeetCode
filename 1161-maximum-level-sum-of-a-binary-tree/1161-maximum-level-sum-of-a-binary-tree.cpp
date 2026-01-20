/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
         if (root == NULL) return 0;

        queue<TreeNode*> que;
        que.push(root);

        int maxsum = INT_MIN , idx = 1 , curridx = 1;
        while(!que.empty()) {
            int size = que.size();
            int currlevelsum  = 0;
            for(int i = 0; i < size; i++) {
                auto a = que.front();
                que.pop();

                currlevelsum += a->val;

                if(a->left != NULL) {
                    que.push(a->left);
                }
                if(a->right != NULL) {
                    que.push(a->right);
                }
            }
            if(maxsum < currlevelsum) {
                maxsum = currlevelsum;
                idx = curridx;
            }
            curridx++;
        }

        return idx;
    }
};