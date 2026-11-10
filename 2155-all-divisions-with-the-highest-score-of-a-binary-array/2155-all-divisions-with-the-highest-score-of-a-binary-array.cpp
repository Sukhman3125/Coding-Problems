class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref0(n), suff1(n);
        pref0[0] = 1 - nums[0];
        suff1[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            pref0[i] = pref0[i - 1] + 1 - nums[i];
            suff1[n - i - 1] = suff1[n - i] + nums[n - i - 1];
        }
        vector<int> ans;
        int maxScore = 0;
        for (int i = 0; i <= n; i++) {
            int score;
            if (i == 0)
                score = suff1[0];
            else if (i == n)
                score = pref0[n - 1];
            else
                score = pref0[i - 1] + suff1[i];
            if (score >= maxScore) {
                if (score > maxScore)
                    ans.clear();
                maxScore = score;
                ans.push_back(i);
            }
        }
        return ans;
    }
};