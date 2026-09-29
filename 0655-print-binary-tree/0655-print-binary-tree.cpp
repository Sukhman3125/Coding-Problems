/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    using t = tuple<TreeNode*, int, int>;

private:
    int height(TreeNode* node) {
        if (!node)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        vector<vector<string>> ans(h, vector<string>((1 << h) - 1, ""));
        int n = ans[0].size();
        queue<t> q;
        q.push({root, 0, (n - 1) / 2});
        while (!q.empty()) {
            auto [node, r, c] = q.front();
            q.pop();
            ans[r][c] = to_string(node->val);
            if (node->left) {
                q.push({node->left, r + 1, c - (1 << (h - r - 2))});
            }
            if (node->right) {
                q.push({node->right, r + 1, c + (1 << (h - r - 2))});
            }
        }
        return ans;
    }
};