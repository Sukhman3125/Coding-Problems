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
    vector<TreeNode*> ans;
    TreeNode* root;
    vector<TreeNode*> nodes;

    void copyTree() {
        if (!root)
            return;

        TreeNode* newRoot = new TreeNode(0);

        queue<TreeNode*> qOrig;
        queue<TreeNode*> qCopy;

        qOrig.push(root);
        qCopy.push(newRoot);

        while (!qOrig.empty()) {
            TreeNode* orig = qOrig.front();
            TreeNode* copy = qCopy.front();

            qOrig.pop();
            qCopy.pop();

            if (orig->left) {
                copy->left = new TreeNode(0);
                qOrig.push(orig->left);
                qCopy.push(copy->left);
            }

            if (orig->right) {
                copy->right = new TreeNode(0);
                qOrig.push(orig->right);
                qCopy.push(copy->right);
            }
        }

        ans.push_back(newRoot);
    }

    void recur(int idx, int nodesLeft) {
        if (nodesLeft == 0) {
            copyTree();
            return;
        }
        if (idx == (int)nodes.size())
            return;

        TreeNode* node = nodes[idx];

        recur(idx + 1, nodesLeft);

        if (nodesLeft >= 2) {
            node->left = new TreeNode(0);
            node->right = new TreeNode(0);
            nodes.push_back(node->left);
            nodes.push_back(node->right);

            recur(idx + 1, nodesLeft - 2);

            nodes.pop_back();
            nodes.pop_back();
            node->left = nullptr;
            node->right = nullptr;
        }
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};

        root = new TreeNode(0);
        nodes.push_back(root);

        recur(0, n-1);
        return ans;
    }
};