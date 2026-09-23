class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        if(target < 0) return -1;
        int subSize = -1;
        int i=0, j=0;
        int sum = 0;
        while(j<n){
            sum += nums[j];
            while(sum>target){
                sum -= nums[i];
                i++;
            }
            if(sum==target){
                subSize = max(subSize, j-i+1);
            }
            j++;
        }
        if(subSize == -1) return -1;
        return n-subSize;
    }
};