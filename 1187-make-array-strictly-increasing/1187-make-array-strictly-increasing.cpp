class Solution {
private:
    static inline int INF = INT_MAX;
    int recur(vector<int>& arr1, vector<int>& arr2, vector<vector<int>>& dp, int i=0, int j=-1){
        int n = arr1.size(), m = arr2.size();
        if (i == n) return 0;

        int &res = dp[i][j + 1];
        if (res != -1) return res;

        int prev;
        if (j != -1) prev = arr2[j];
        else prev = (i == 0) ? -1 : arr1[i - 1];

        res = INF;

        // keep
        if (arr1[i] > prev)
            res = min(res, recur(arr1, arr2, dp, i + 1, -1));

        // replace
        int k = (j != -1) ? j + 1: upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (k < m) {
            int sub = recur(arr1, arr2, dp, i + 1, k);
            if (sub != INF) res = min(res, 1 + sub);
        }

        return res;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        set<int> st;
        for (auto it : arr2)
            st.insert(it);
        arr2.clear();
        for (auto it : st)
            arr2.push_back(it);

        int n = arr1.size(), m = arr2.size();
        vector<vector<int>> dp(n, vector<int>(m + 1, -1));
        int ans = recur(arr1, arr2, dp);
        return ans >= INF ? -1 : ans;
    }
};