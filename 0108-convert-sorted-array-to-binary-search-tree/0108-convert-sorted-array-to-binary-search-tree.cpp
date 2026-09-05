class Solution {
private:
    TreeNode* _(vector<int>& nums, int l = 0, int r = INT_MIN){
        if(r==INT_MIN) r = nums.size()-1;
        if(l>r) return nullptr;
        int m = l + (r-l)/2;
        TreeNode* curr = new TreeNode(nums[m]);
        curr->left = _(nums, l, m-1);
        curr->right = _(nums,m+1, r);
        return curr;
    } 
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _(nums);
    }
};