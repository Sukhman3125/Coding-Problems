class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> ans = {-1,-1};
        int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(nums[i] + nums[j] != target) continue;
                if(nums[i] <= nums[j]) continue;
                if(ans[0] == -1 || nums[i] * nums[j] > nums[ans[0]] * nums[ans[1]]){
                    ans = {i,j};
                }
            }
        }
        return ans;
    }
};