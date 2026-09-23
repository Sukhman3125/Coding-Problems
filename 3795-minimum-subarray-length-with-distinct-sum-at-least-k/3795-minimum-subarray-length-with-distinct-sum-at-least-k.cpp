class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<int, int> freq;
        int i = 0, n = nums.size();
        int ans = -1;
        for (int j = 0; j < n; j++) {
            if (!freq.contains(nums[j])) {
                sum += nums[j];
            }
            freq[nums[j]]++;
            while (sum >= k) {
                if (ans == -1)
                    ans = j - i + 1;
                ans = min(ans, j - i + 1);
                freq[nums[i]]--;
                if (freq[nums[i]] == 0) {
                    freq.erase(nums[i]);
                    sum -= nums[i];
                }
                i++;
            }
        }
        return ans;
    }
};