class Solution {
private:
    int find(vector<vector<int>>& v, int target) {
        int l = 0, r = v.size() - 1;
        int ans = -1;

        while (l <= r) {
            int m = l + (r - l) / 2;

            if (v[m][0] >= target) {  
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }

public:
    vector<int> findRightInterval(vector<vector<int>>& in) {
        unordered_map<int, int> idxOf;
        int n = in.size();

        for (int i = 0; i < n; i++) {
            idxOf[in[i][0]] = i;
        }

        sort(in.begin(), in.end(),
             [](const auto& a, const auto& b) {
                 return a[0] < b[0];
             });

        vector<int> ans(n);

        for (auto& it : in) {
            int s = it[0], e = it[1];

            int i = find(in, e);

            if (i == -1)
                ans[idxOf[s]] = -1;
            else
                ans[idxOf[s]] = idxOf[in[i][0]];
        }

        return ans;
    }
};