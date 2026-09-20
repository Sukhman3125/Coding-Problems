class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int i=0, n=nums.size(), j=0;
        int ans = INT_MAX;
        while(i<n){
            while(j<n && nums[j] <= 1LL*k*nums[i]){
                j++;
            }
            ans = min(ans, n - (j - i));
            i++;
        }
        return ans==INT_MAX?0:ans;
    }
};