class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int prefE = 0, prefO = 0, suffE = 0, suffO = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0)
                suffE += nums[i];
            if (i % 2 == 1)
                suffO += nums[i];
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                suffE -= nums[i];
                if (prefE + suffO == prefO + suffE) cnt++;
                prefE += nums[i];
            } else {
                suffO -= nums[i];
                if (prefO + suffE == prefE + suffO) cnt++;
                prefO += nums[i];
            }
        }
        return cnt;
    }
};