class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            int sum = 0;
            for(int j=i;j<n;j++){
                st.insert(2*nums[j]);
                sum += nums[j];
                if(st.contains(sum%k))
                    ans = max(ans, j-i+1);
                int x = (2LL * nums[j]) % k;
                if (x < 0) x += k;
                st.insert(x);

                int rem = sum % k;
                if (rem < 0) rem += k;
                if(rem==0 || st.contains(rem)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
};