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
private:
    int sum = 0;
    void recur(TreeNode* node){
        if(!node) return;
        recur(node->right);
        sum += node->val;
        node->val = sum;
        recur(node->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        recur(root);
        return root;
    }
};