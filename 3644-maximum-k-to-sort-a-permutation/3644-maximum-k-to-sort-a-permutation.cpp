class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int AND = INT_MAX, n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == i)
                continue;
            AND &= nums[i];
        }
        return AND == INT_MAX? 0: AND;
    }
};