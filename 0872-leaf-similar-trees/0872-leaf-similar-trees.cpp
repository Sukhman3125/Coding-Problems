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
    void recur(TreeNode* root, vector<int>& ans){
        if(!root->left && !root->right){
            ans.push_back(root->val);
            return;
        }
        if(root->left) recur(root->left, ans);
        if(root->right) recur(root->right, ans);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> _1;
        vector<int> _2;
        recur(root1,_1);
        recur(root2,_2);
        return _1 == _2;
    }
};