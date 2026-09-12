class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> v(2);
        int maxi = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {
            v[nums[right]]++;

            while (left < n && v[0] > k) {
                v[nums[left]]--;
                left++;
            }

            maxi = max(maxi, right - left + 1);
        }

        return maxi;
    }
};