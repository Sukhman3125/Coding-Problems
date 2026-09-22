/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> arr;
        while(head){
            arr.push_back(head->val);
            head = head->next;
        }
        return _(arr);
    }
};