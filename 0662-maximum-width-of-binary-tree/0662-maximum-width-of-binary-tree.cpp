class Solution {
public:
    int findwidth(TreeNode* root) {
        if (root == NULL) return 0;

        long long maxwidth = 0;
        queue<pair<TreeNode*, long long>> que;
        que.push({root, 0});

        while (!que.empty()) {
            int size = que.size();
            long long minIndex = que.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto next = que.front();
                que.pop();

                TreeNode* node = next.first;
                long long idx = next.second - minIndex;

                if (i == 0) first = idx;
                if (i == size - 1) last = idx;

                if (node->left != NULL) {
                    que.push({node->left, 2 * idx + 1});
                }
                if (node->right != NULL) {
                    que.push({node->right, 2 * idx + 2});
                }
            }

            maxwidth = max(maxwidth, last - first + 1);
        }

        return (int)maxwidth;
    }

    int widthOfBinaryTree(TreeNode* root) {
        return findwidth(root);
    }
};
