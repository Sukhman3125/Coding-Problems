class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if(nums.size()==1 && nums[0] < 0) 
            return nums[0];
        bool hasOnly0 = true, hasPos = false;
        int minNeg = INT_MIN, negCnt = 0;
        long long ans = 1;
        for(auto it:nums){
            if(it!=0) {
                hasOnly0 = false;
                ans *= it;
            }
            if(it<0) {
                negCnt++;
                minNeg = max(minNeg, it);
            }
            if(it>0) hasPos = true;
        }
        if(hasOnly0) return 0;
        if(!hasPos && negCnt == 1) return 0;
        if(ans > 0) return ans;
        return ans/minNeg;
    }
};