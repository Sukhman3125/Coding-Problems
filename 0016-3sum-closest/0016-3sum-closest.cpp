class Solution {
private:
    int bin(vector<int>& v, int t, int l, int r) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (v[m] == t) {
                return t;
            }
            if (v[m] < t) {
                l = m + 1;
                maxi = v[m];
            } else {
                r = m - 1;
                mini = v[m];
            }
        }
        if (maxi == INT_MIN) return mini;
        if (mini == INT_MAX) return maxi;
        if (t - maxi < mini - t) 
            return maxi;
        return mini;
    }

public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans;
        int minDiff = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int t = target - nums[i] - nums[j];
                int curr = bin(nums, t, j + 1, n-1);
                if(abs(curr-t) < minDiff){
                    minDiff = abs(curr-t);
                    ans = nums[i] + nums[j] + curr;
                }
            }
        }
        return ans;
    }
};