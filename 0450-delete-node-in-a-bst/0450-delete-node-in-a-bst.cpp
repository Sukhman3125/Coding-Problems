class Solution {
    using p = pair<TreeNode*, TreeNode*>;

private:
    p find(TreeNode* node, int& key, TreeNode* parent = nullptr) {
        if (!node)
            return {nullptr, nullptr};

        if (node->val == key)
            return {node, parent};

        p left = find(node->left, key, node);
        if (left.first)
            return left;

        return find(node->right, key, node);
    }

public:
    TreeNode* deleteNode(TreeNode* root, int& key) {
        auto [node, par] = find(root, key);

        if (!node)
            return root;

        TreeNode* replacement;

        if (!node->left) {
            replacement = node->right;
        }
        else {
            replacement = node->left;

            TreeNode* cur = replacement;
            while (cur->right)
                cur = cur->right;

            cur->right = node->right;
        }

        if (!par)
            return replacement;

        if (par->left == node)
            par->left = replacement;
        else
            par->right = replacement;

        return root;
    }
};