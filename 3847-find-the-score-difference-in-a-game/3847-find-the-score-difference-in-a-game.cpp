class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int scoreDiff = 0, n = nums.size();
        bool active = true;
        for(int i=0;i<n;i++){
            if(nums[i]%2) active = !active;
            if(i%6 == 5) active = !active;
            scoreDiff += nums[i] * (active?1:-1);
        }
        return scoreDiff;
    }
};