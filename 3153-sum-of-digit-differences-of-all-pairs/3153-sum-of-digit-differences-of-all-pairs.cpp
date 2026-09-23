class Solution {
private:
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int freq[10] = {0};
        int d = log10(nums[0]) + 1;
        int n = nums.size();
        long long ans = 0;
        for(int i=0;i<d;i++){
            for(auto& it:freq) it = 0;
            for(auto& it:nums){
                freq[it%10]++;
                it/=10;
            }
            for(auto& it:freq){
                ans += 1LL * (it) * (n-it);
            }
        }
        return ans/2;
    }
};