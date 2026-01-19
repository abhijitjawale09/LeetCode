class Solution {
public: 
    TreeNode* build(vector<int>& inorder, int x, int y,
                    vector<int>& postorder, int a, int b) {
        if (x > y || a > b) {
            return NULL;
        }

        TreeNode* t = new TreeNode(postorder[b]);

        int SI = x;
        while (SI <= y && inorder[SI] != t->val) SI++;

        int leftSize = SI - x;

        t->left = build(inorder, x, SI - 1,
                        postorder, a, a + leftSize - 1);

        t->right = build(inorder, SI + 1, y,
                         postorder, a + leftSize, b - 1);

        return t;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1);
    }
};
