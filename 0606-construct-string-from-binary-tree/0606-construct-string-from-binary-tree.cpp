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
    string ans;
    void recur(TreeNode* node){
        if(!node) return;
        ans += to_string(node->val);
        if(node->left){
            ans += '(';
            recur(node->left);
            ans += ')';
            if(node->right){
                ans += '(';
                recur(node->right);
                ans += ')';
            }
            return;
        }
        if(node->right){
            ans += "()(";
            recur(node->right);
            ans += ')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        recur(root);
        return ans;
    }
};