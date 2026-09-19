class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            int curr = 1;
            for(int j=i;j<n;j++){
                curr = lcm(curr, nums[j]);
                if(curr==k) ans++;
                else if(curr>k) break;
            }
        }
        return ans;
    }
};