class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        vector<int> temp = nums;
        for(auto it:temp){
            nums.push_back(it);
        }
        long long sum1 = 0;
        long long sum2 = 0;
        int n = temp.size();
        int i = 0;
        for(;i<n/2;i++){
            sum1 += nums[i];
        }
        for(;i<n;i++){
            sum2 += nums[i];
        }
        int cnt = 0;
        if(sum1 > sum2) cnt++;
        for(i=0;i<n-1;i++){
            sum1 -= nums[i];
            sum2 += nums[n+i];
            sum1 += nums[i+n/2];
            sum2 -= nums[i+n/2];
            if(sum1>sum2) cnt++;
        }
        return cnt;
    }
};