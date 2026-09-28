class Solution {
private:
    static inline int f[100001];
    int anomally_cnt = 0;
    void inc(int x){
        if(f[x]==1) anomally_cnt++;
        f[x]++;
    }
    void dec(int x){
        f[x]--;
        if(f[x]==1) anomally_cnt--;
    }
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        for(auto& it:f) it = 0;
        int i = 0, j = 0, n = nums.size();
        long long ans = 0;
        long long sum = 0;
        while(i<k){
            inc(nums[i]);
            sum += nums[i];
            i++;
        }
        if(!anomally_cnt) ans = max(ans, sum);
        while(i<n){
            inc(nums[i]);
            dec(nums[j]);
            sum += nums[i] - nums[j];
            if(!anomally_cnt) ans = max(ans, sum);
            i++, j++;
        }
        return ans;
    }
};