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
    int maxsum;
    int solve(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left = solve(root->left);
        int right =  solve(root->right);


        int eak_acha = max(left , right) + root->val;

        int root_acha = root->val;

        int neeche_se_aacha = left + root->val + right;

        maxsum = max({maxsum , eak_acha , root_acha , neeche_se_aacha });

        return max(root_acha , eak_acha);
    }

    int maxPathSum(TreeNode* root) {

        if(!root) {
            return 0;
        }
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
    }
};