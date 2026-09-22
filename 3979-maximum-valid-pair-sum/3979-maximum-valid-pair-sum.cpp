class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffMax(n);
        suffMax[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffMax[i] = max(nums[i], suffMax[i+1]);
        }
        int ans = 0;
        for(int i=0;i<n-k;i++){
            ans = max(ans, nums[i] + suffMax[i+k]);
        }
        return ans;
    }
};