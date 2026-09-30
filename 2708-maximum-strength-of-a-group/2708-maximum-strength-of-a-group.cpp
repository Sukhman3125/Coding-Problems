class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==1 && nums[0] < 0) 
            return nums[0];
        bool hasOnly0 = true, hasPos = false;
        int minNeg = INT_MIN;
        vector<int> neg;
        long long ans = 1;
        for(auto it:nums){
            if(it!=0) {
                hasOnly0 = false;
                ans *= it;
            }
            if(it<0) {
                neg.push_back(it);
                minNeg = max(minNeg, it);
            }
            if(it>0) hasPos = true;
        }
        if(hasOnly0) return 0;
        if(!hasPos && neg.size() == 1) return 0;
        if(ans > 0) return ans;
        return ans/minNeg;
    }
};