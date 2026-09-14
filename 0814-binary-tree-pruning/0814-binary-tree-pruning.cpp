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
    bool recur(TreeNode* node, TreeNode* par = nullptr, bool left = false){
        if(!node) return false;
        bool l = recur(node->left, node, true);
        bool r = recur(node->right, node, false);
        bool val = l || r || (node->val == 1);
        if(!val){
            if(par != nullptr){
                if(left) par->left = nullptr;
                else par->right = nullptr;
            }
        }
        return val;
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        bool is1 = recur(root);
        if(!is1) return nullptr;
        return root;
    }
};