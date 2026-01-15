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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int , int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        int rootIdx = 0;
        return build(preorder, inorderMap, rootIdx, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorderMap, int &rootIdx, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int rootVal = preorder[rootIdx++];
        TreeNode* newNode = new TreeNode(rootVal);

        int pivot = inorderMap[rootVal];

        newNode->left = build(preorder, inorderMap, rootIdx, left, pivot - 1);
        newNode->right = build(preorder, inorderMap, rootIdx, pivot + 1, right);

        return newNode;
    }
};
