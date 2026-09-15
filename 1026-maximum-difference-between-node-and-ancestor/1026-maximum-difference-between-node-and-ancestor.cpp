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
private:
    int ans = 0;
    pair<int, int> recur(TreeNode* node) {
        if (!node)
            return {INT_MAX, INT_MIN};
        auto [minL, maxL] = recur(node->left);
        auto [minR, maxR] = recur(node->right);
        int mn = min(node->val, min(minL, minR));
        int mx = max(node->val, max(maxL, maxR));

        ans = max(ans, max(abs(node->val - mn), abs(node->val - mx)));

        return {mn, mx};
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        recur(root);
        return ans;
    }
};