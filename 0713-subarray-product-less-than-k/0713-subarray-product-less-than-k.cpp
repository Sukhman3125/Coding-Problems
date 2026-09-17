class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int ans = 0;
        int i=0, j=0;
        int n = nums.size();
        int prod = 1;
        while(i<n){
            prod *= nums[i];
            while(prod >= k){
                prod/=nums[j];
                j++;
            }
            ans += i-j+1;
            i++;
        }
        return ans;
    }
};