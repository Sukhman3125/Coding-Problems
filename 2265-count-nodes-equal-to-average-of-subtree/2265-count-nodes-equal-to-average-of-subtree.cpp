class Solution {
private:
    vector<int> dataCollector(TreeNode* node){
        if(!node) return {0,0};
        vector<int> left = dataCollector(node->left);
        vector<int> right = dataCollector(node->right);
        return {left[0]+right[0]+node->val,left[1]+right[1]+1};
    }
    int avg(TreeNode* node){
        vector<int> data = dataCollector(node);
        return data[0]/data[1];
    }
    void dfs(TreeNode* node, int& cnt){
        if(!node) return;
        if(node->val == avg(node)) cnt++;
        dfs(node->left,cnt);
        dfs(node->right,cnt);
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        dfs(root,cnt);
        return cnt;
    }
};