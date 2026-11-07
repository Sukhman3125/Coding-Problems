class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini = INT_MAX;
        for (int i = 0; i < nums.size(); i += 2) {
            int curr = stoi(to_string(nums[i]) + to_string(nums[i + 1]));
            mini = min(curr, mini);
        }
        return mini;
    }
};