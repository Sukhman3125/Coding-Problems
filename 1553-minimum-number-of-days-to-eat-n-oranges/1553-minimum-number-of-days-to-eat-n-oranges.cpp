class Solution {
private:
    unordered_map<int, int> dp;
    int recur(int n){
        if(dp.contains(n)) 
            return dp[n];
        if(n==1)
            return 1;
        if(n==0)
            return 0;
        int _2 = n%2 + recur(n/2);
        int _3 = n%3 + recur(n/3);
        return dp[n] = 1+min(_2, _3);
    }
public:
    int minDays(int n) {
        return recur(n);
    }
};