class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        int dp[1000002] = {0};
        int ans = 0;
        for(auto it:arr){
            dp[it] = max({dp[it],dp[it-1]+1,dp[it+1]+1});
            ans = max(ans,dp[it]);
        }
        return ans;
    }
};