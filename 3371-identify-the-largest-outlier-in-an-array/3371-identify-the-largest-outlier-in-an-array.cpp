class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto it : nums) {
            freq[it]++;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int maxi = INT_MIN;
        for (auto outlier : nums) {
            int sumAfterRemoval = sum - outlier;
            if (abs(sumAfterRemoval) % 2 == 1)
                continue;
            int targetSum = sumAfterRemoval / 2;
            if (outlier == targetSum && freq[targetSum] < 2)
                continue;
            if (freq[targetSum] != 0) {
                maxi = max(outlier, maxi);
            }
        }
        return maxi;
    }
};