class Solution {
private:
    int n;
    pair<int, int> monotonicity(vector<int>& nums) {
        int incStreak = 1, decStreak = 1;
        int maxIncSub = 1, maxDecSub = 1;
        int incPivot = -1, decPivot = -1;
        for (int j = 1; j < 2 * n; j++) {
            int i = j % n;
            int _i = (j - 1) % n;
            if (nums[i] < nums[_i]) {
                decStreak++;
                incPivot = i;
                maxIncSub = max(maxIncSub, incStreak);
                incStreak = 1;
            } else if (nums[i] > nums[_i]) {
                incStreak++;
                decPivot = i;
                maxDecSub = max(maxDecSub, decStreak);
                decStreak = 1;
            } else {
                incStreak++;
                decStreak++;
            }
        }
        maxIncSub = max(maxIncSub, incStreak);
        maxDecSub = max(maxDecSub, decStreak);
        if (maxIncSub >= n)
            return {0, incPivot}; // cyclically inc
        if (maxDecSub >= n)
            return {1, decPivot}; // cyclically dec
        return {-1, -1};
    }

public:
    int minOperations(vector<int>& nums) {
        n = nums.size();
        auto [mono, pvt] = monotonicity(nums);
        if (mono == -1)
            return -1;
        if (pvt == -1)
            return mono;
        if (mono == 0)
            return min(pvt, n - pvt + 2);

        return 1 + min(pvt, n - pvt);
    }
};