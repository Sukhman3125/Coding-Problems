class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int i=0, j=0, n = nums.size(), ans = 1;
        while(j<n){
            int r = ((nums[j]%k) + k) %k;
            while(j<n && ((nums[j] % k) + k) % k == r){
                j++;
            }

            if(r==0)
                ans = max(ans, j-i);
            else{
                int need = k/gcd(k,r);
                int validLen = (j-i) - ((j-i-1)%need);
                ans = max(ans, validLen);
            }
            i=j;
        }
        return ans;
    }
};