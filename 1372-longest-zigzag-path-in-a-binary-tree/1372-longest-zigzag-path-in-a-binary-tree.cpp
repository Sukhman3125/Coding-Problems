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
    int recur(TreeNode* node, string prevDir, int cnt = 0){
        if(!node) return cnt;
        int left = 0;
        int right = 0;
        if(node->left){
            if(prevDir=="left") left = recur(node->left, "left", 1);
            else left = recur(node->left, "left", cnt+1);
        }
        if(node->right){
            if(prevDir=="right") right = recur(node->right,"right",1);
            else right = recur(node->right,"right",cnt+1);
        } 
        return max({cnt,left,right});
    }
public:
    int longestZigZag(TreeNode* root) {
        return max
        (
            recur(root,"left"),
            recur(root,"right")
        );
    }
};