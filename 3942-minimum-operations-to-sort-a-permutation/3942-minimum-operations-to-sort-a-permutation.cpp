class Solution {
private:
    int n;
    pair<string, int> pivot(vector<int>& nums) {
        int incPvt = 0, decPvt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                if (incPvt == 0)
                    incPvt = i;
                else
                    incPvt = -1;
            } else {
                if (decPvt == 0)
                    decPvt = i;
                else
                    decPvt = -1;
            }
            if (incPvt == -1 && decPvt == -1)
                return {"unsortable", -1};
        }
        if (incPvt == 0)
            return {"inc", 0};
        if (decPvt == 0)
            return {"dec", 0};
        if (incPvt != -1 && nums[0] > nums[n - 1])
            return {"inc", incPvt};
        if (decPvt != -1 && nums[0] < nums[n - 1])
            return {"dec", decPvt};
        return {"unsortable", -1};
    }

public:
    int minOperations(vector<int>& nums) {
        n = nums.size();
        auto [order, pvt] = pivot(nums);
        if (order == "unsortable")
            return -1;
        if (pvt == 0) { // sorted already
            return order == "inc" ? 0 : 1;
        }
        if (order == "inc")
            return min(pvt, n - pvt + 2);
        return min(pvt + 1, n - pvt + 1);
    }
};