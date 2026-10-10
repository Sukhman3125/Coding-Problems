class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int k = k1 + k2, n = nums1.size();
        long long diffSum = 0;
        int mx = 0;

        for(int i = 0; i < n; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
            diffSum += nums1[i];
            mx = max(mx, nums1[i]);
        }

        if(diffSum <= k) return 0;

        int l = 0, r = mx;

        while(l < r) {
            int mid = l + (r - l) / 2;
            long long ops = 0;

            for(int i = 0; i < n; i++) {
                ops += max(0, nums1[i] - mid);
            }

            if(ops <= k)
                r = mid;
            else
                l = mid + 1;
        }

        int x = l;

        for(int i = 0; i < n; i++) {
            k -= max(0, nums1[i] - x);
            nums1[i] = min(nums1[i], x);
        }

        for(int i = 0; i < n && k > 0; i++) {
            if(nums1[i] == x) {
                nums1[i]--;
                k--;
            }
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            ans += 1LL * nums1[i] * nums1[i];
        }

        return ans;
    }
};