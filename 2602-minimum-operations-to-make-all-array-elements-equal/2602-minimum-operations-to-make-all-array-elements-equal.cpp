class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), m = queries.size();
        vector<long long> pref(n);
        vector<long long> suff(n);
        pref[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + nums[i];
            suff[n - 1 - i] = suff[n - i] + nums[n - 1 - i];
        }
        vector<long long> ans(m);
        for (int i = 0; i < m; i++) {
            int pvt = lower_bound(nums.begin(), nums.end(), queries[i]) -
                      nums.begin();
                    
            long long smaller = 0;
            long long larger = 0;
            if (pvt != 0) {
                smaller = 1LL * queries[i] * pvt - pref[pvt - 1];
            }
            if (pvt != n) {
                larger = suff[pvt] - 1LL * queries[i] * (n - pvt);
            }
            ans[i] = smaller + larger;
        }
        return ans;
    }
};