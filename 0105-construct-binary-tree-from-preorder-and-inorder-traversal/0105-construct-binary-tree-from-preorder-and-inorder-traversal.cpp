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
        unordered_map<int , int> mp;

        for(int i =0; i < preorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int rootIdx = 0;
        return build(preorder , mp , rootIdx , 0 , inorder.size() -1);
    }
    TreeNode* build(vector<int>&preorder , unordered_map<int, int> &mp , int &rootidx ,int left , int right) {
        if(left > right) {
            return NULL;
        }
        int rootval = preorder[rootidx++];

        TreeNode* newNode = new TreeNode(rootval);
        int pivot = mp[rootval];

        newNode->left = build(preorder , mp , rootidx , left , pivot - 1);
        newNode->right = build(preorder , mp , rootidx , pivot + 1 , right);

        return newNode;
    } 
};