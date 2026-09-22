class Solution {
private:
    int recur(vector<int>& nums, vector<int>& dp, vector<bool>& vis, int i) {
        if (dp[i] != -1)
            return dp[i];
        if (vis[i])
            return 0;
        vis[i] = true;
        return dp[i] = 1 + recur(nums, dp, vis, nums[i]);
    }

public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        vector<bool> vis(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, recur(nums, dp, vis, i));
        }
        return ans;
    }
};