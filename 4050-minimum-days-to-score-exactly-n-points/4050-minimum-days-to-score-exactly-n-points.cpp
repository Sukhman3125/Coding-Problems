class Solution {
public:
    int minDays(int n) {
        // 1, 3, 6, 10, 15
        const int inf = 1e9;
        vector<int> dp(n+1,inf);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            for(long long k = 1; k*(k+1)/2 <=i; k++){
                int curr = k*(k+1)/2;
                dp[i] = min(dp[i], dp[i-curr] + (int)k+1);
            }
        }
        return dp[n]-1;
    }
};