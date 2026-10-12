class Solution {
private:
    static inline int MOD = 1e9 + 7;

public:
    int maxSum(vector<int>& nums, int k) {
        int bitCnt[32] = {0};
        // nums = {15};
        for (auto it : nums) {
            int i = 0;
            while (it) {
                bitCnt[32 - i - 1] += it & 1;
                it >>= 1;
                i++;
            }
        }

        // for(auto it:bitCnt) cout<<it<<" ";
        int ans = 0;
        while (k) {
            int curr = 0;
            for (auto& b : bitCnt) {
                curr <<= 1;
                if (b) {
                    b--;
                    curr |= 1;
                }
            }
            if (!curr)
                break;
            ans = (ans + (1LL * curr * curr) % MOD) % MOD;
            k--;
        }
        return ans;
    }
};