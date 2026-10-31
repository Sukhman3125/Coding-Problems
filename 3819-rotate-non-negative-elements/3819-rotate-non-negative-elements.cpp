class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNegs;
        int n = nums.size();
        for (auto it : nums) {
            if (it >= 0)
                nonNegs.push_back(it);
        }
        int m = nonNegs.size();
        if(m == 0) 
            return nums;
        k = k % m;
        reverse(nonNegs.begin(), nonNegs.begin() + k);
        reverse(nonNegs.begin() + k, nonNegs.end());
        reverse(nonNegs.begin(), nonNegs.end());
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] < 0)
                continue;
            nums[j] = nonNegs[i];
            i++;
        }
        return nums;
    }
};