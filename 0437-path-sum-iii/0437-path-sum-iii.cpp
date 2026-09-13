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
    int target;
    int cnt = 0;
    void _(TreeNode* node){
        if(!node) return; 
        dfs(node);
        if(node->left) _(node->left);
        if(node->right) _(node->right);
    }
    void dfs(TreeNode* node, long long sum = 0){
        if(!node) return;
        sum += node->val;
        if(sum == target) cnt++;
        if(node->left) dfs(node->left,sum);
        if(node->right) dfs(node->right,sum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        _(root);
        return cnt;
    }
};