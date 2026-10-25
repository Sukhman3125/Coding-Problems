class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int target = 0;
        for (auto it : nums)
            target = (target + it) % p;

        if (!target)
            return 0;

        int prefSum = 0, n = nums.size();
        unordered_map<int, int> idx; // index of key as last pref sum value
        idx[0] = -1;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            prefSum = (nums[i] + prefSum) % p;
            int x = (prefSum - target + p) % p;
            if (idx.contains(x))
                ans = min(ans, i - idx[x]);
            idx[prefSum] = i;
        }
        return ans == INT_MAX || ans == n ? -1 : ans;
    }
};