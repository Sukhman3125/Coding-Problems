class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        long long streak = 0;
        for(auto it:nums){
            if(it <= maxK && it >= minK){
                streak++;
            }else{
                ans += streak*(streak+1)/2;
                streak = 0;
            }
        }
        ans += streak*(streak+1)/2;
        return ans;
    }
};