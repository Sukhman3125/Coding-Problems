class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        int n = nums.size();
        if(n == 0) return 0;

        vector<long long> dp(n);
        dp[0] = nums[0];

        for(int i = 1; i < n; i++) {
            dp[i] = nums[i];

            dp[i] = max(dp[i], dp[i-1]);
            if(colors[i] != colors[i-1])
                dp[i] = max(dp[i], dp[i-1] + nums[i]);
            if(i >= 2)
                dp[i] = max(dp[i], dp[i-2] + nums[i]);
        }

        return dp[n-1];
    }
};