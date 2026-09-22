class Solution {
private:
    static inline pair<int, int> dirs1[4] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    static inline pair<int, int> dirs2[4] = {{0, 0}, {-1, 0}, {0, 1}, {-1, 1}}; 
    static inline pair<int, int> dirs3[4] = {{0, 0}, {-1, 0}, {0, -1}, {-1, -1}}; 
    static inline pair<int, int> dirs4[4]  = {{0, 0}, {1, 0}, {0, -1}, {1, -1}};  

    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        unordered_set<pair<int, int>, PairHash> s;
        for (auto it : coordinates) {
            s.insert({it[0], it[1]});
        }

        unordered_set<pair<int, int>, PairHash> vis; 
        vector<long long> ans(5, 0);
        ans[0] = 1LL * (m - 1) * (n - 1);

        pair<int,int> offsets[4] = {
            {0, 0},
            {0, -1},
            {-1, 0},
            {-1, -1}
        };

        for (auto [i, j] : s) {
            for (auto& [oi, oj] : offsets) {
                int ti = i + oi, tj = j + oj; 
                if (ti < 0 || tj < 0 || ti > m - 2 || tj > n - 2) continue;
                if (vis.contains({ti, tj})) continue;
                vis.insert({ti, tj});

                int cnt = 0;
                for (auto& [di, dj] : dirs1) {
                    if (s.contains({ti + di, tj + dj})) cnt++;
                }
                ans[cnt]++;
                ans[0]--;
            }
        }
        return ans;
    }
};