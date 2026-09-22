class Solution {
private:
    int greaterThan(vector<vector<int>>& v, int t) {
        int l = 0, r = v.size() - 1;
        int ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m][1] >= t) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
    int lessThan(vector<vector<int>>& v, int t) {
        int l = 0, r = v.size() - 1;
        int ans = -1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m][0] <= t) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return ans;
    }

public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end(),
             [](const auto& a, const auto& b) { return a[0] < b[0]; });
        int n = coins.size();
        vector<long long> pref(n);
        pref[0] = 1LL * coins[0][2] * (coins[0][1] - coins[0][0] + 1);
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] +
                      1LL * coins[i][2] * (coins[i][1] - coins[i][0] + 1);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = coins[i][0], r = coins[i][1];

            int t = l + k - 1;
            int end = greaterThan(coins, t);
            long long ans1;
            if (end == -1) {
                ans1 = pref[n - 1];
            } else if (t < coins[end][0]) {
                ans1 = (end > 0 ? pref[end - 1] : 0);
            } else {
                ans1 = pref[end] - 1LL * coins[end][2] * (coins[end][1] - t);
            }
            ans1 -= (i > 0 ? pref[i - 1] : 0);
            ans = max(ans, ans1);

            t = r - k + 1;
            int start = lessThan(coins, t);
            long long ans2;
            if (start == -1) {
                ans2 = pref[i];
            } else if (t > coins[start][1]) {
                ans2 = pref[i] - pref[start];
            } else {
                ans2 = pref[i] - (start > 0 ? pref[start - 1] : 0) -
                       1LL * coins[start][2] * (t - coins[start][0]);
            }
            ans = max(ans, ans2);
        }
        return ans;
    }
};