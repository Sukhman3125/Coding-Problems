class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int prefSame = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i])
                break;
            prefSame++;
        }

        int suffStart = n - 1;
        for (int i = n - 1; i >= 1; i--) {
            if (target[i] > target[i - 1])
                break;
            suffStart = i - 1;
        }

        if (prefSame < suffStart)
            return 0;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
            freq[target[i]]--;
        }

        for (auto& [x, count] : freq) {
            if (count != 0)
                return 0;
        }

        return min(prefSame, n - 1) - suffStart + 1;
    }
};