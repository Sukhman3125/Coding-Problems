class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);

        int n = nums.size(), ans = -1;

        while (l <= h) {
            int mid = l + (h - l) / 2;

            int cnt = 0, cur = 0;
            for (int i = 0; i < n; i++) {
                if (cur + nums[i] > mid) {
                    cnt++;
                    cur = nums[i];
                } else {
                    cur += nums[i];
                }
            }

            cnt++;

            if (cnt <= k) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};