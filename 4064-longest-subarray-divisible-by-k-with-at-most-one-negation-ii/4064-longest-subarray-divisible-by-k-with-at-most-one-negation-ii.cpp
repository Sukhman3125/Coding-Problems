class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> preMod(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            preMod[i] = ((preMod[i - 1] + nums[i - 1]) % k + k) % k;
        }

        vector<int> firstOcc(k, -1), lastOcc(k, -1);
        for (int i = 0; i <= n; i++) {
            int v = preMod[i];
            if (firstOcc[v] == -1)
                firstOcc[v] = i;
            lastOcc[v] = i;
        }

        int ans = 0;

        for (int r = 0; r <= n; r++) {
            int l = firstOcc[preMod[r]];
            if (l < r)
                ans = max(ans, r - l);
        }

        vector<vector<int>> groups(k);
        for (int j = 0; j < n; j++) {
            int d = ((2 * (nums[j] % k)) % k + k) % k;
            groups[d].push_back(j);
        }

        for (int m = 0; m < k; m++) {
            if (firstOcc[m] == -1)
                continue;
            int L = firstOcc[m];
            for (int v = 0; v < k; v++) {
                if (lastOcc[v] == -1)
                    continue;
                int R = lastOcc[v] - 1;
                if (R < L)
                    continue;
                int val = lastOcc[v] - L;
                if (val <= ans)
                    continue;

                int d = ((v - m) % k + k) % k;
                auto& g = groups[d];
                if (g.empty())
                    continue;

                auto it = lower_bound(g.begin(), g.end(), L);
                if (it != g.end() && *it <= R) {
                    ans = val;
                }
            }
        }
        return ans;
    }
};