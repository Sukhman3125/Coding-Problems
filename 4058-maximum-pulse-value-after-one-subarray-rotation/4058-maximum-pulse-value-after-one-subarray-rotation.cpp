class Solution {
public:
    long long maxValue(vector<int>& nums) {
        // pulse = evenSum - oddSum
        // rotation -> change odd->even, even->odd
        int n = nums.size();
        vector<long long> sum(n+1,0);
        for(int i=0;i<n;i++){
            sum[i+1] = sum[i] + 1LL * nums[i] * (i%2==0?1:-1);
        }

        long long original = sum[n];
        long long prefMax[2] = {LLONG_MIN, LLONG_MIN};
        long long maxDiff = 0;
        for(int b=2;b<=n;b++){
            int a = b-2;
            int sign = a&1;
            prefMax[sign] = max(prefMax[sign], sum[a]);
            long long curr = prefMax[b&1];
            if(curr != LLONG_MIN){
                maxDiff = max(maxDiff, 2*(curr-sum[b]));
            }
        }
        return original + maxDiff;
    }
};