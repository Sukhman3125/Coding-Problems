class Solution {
private:
    unordered_map<int, int> dp;

public:
    int minDays(int n) {
        if(dp.contains(n)) 
            return dp[n];
        if(n<=1) 
            return n;
        return dp[n] = 1+min(
            n%2 + minDays(n/2),
            n%3 + minDays(n/3)
        );
    }
};