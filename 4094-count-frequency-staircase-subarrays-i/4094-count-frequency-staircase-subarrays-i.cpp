class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            unordered_map<int, pair<int, int>> freq; // order, freq
            int k = 1, unbalanced = 0;
            for (int j = i; j < n; j++) {
                auto& [order, f] = freq[nums[j]];
                if (f == 0) {
                    order = k++;
                    unbalanced++;
                }
                f++;
                if (f == order)
                    unbalanced--;
                if (f > order)
                    break;
                if (unbalanced == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};