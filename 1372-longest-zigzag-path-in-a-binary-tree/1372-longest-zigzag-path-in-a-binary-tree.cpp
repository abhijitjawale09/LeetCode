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
    int maxcount = 0;
    void dfs(TreeNode* root , bool dir ,int len) { 
        if(root == NULL) {
            return ;
        }

        maxcount = max(maxcount , len);

        if(dir == 0) {
            dfs(root->right , 1, len + 1);
            dfs(root->left , 0 , 1);
        }else{
            dfs(root->left , 0 , len +1 );
            dfs(root->right , 1 , 1);
        }

    }
    int longestZigZag(TreeNode* root) {
        if(!root) {
            return 0;
        }
        dfs(root->left , 0 , 1);
        dfs(root->right , 1 , 1);
        return maxcount;
    }
};