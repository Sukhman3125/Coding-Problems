class Solution {
    using p = pair<int, int>;
    static inline int INF = INT_MAX;
    static inline int MOD = 1e9 + 7;
    vector<int> evaluateDistFromN(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : edges) {
            adj[it[0] - 1].push_back({it[2], it[1] - 1});
            adj[it[1] - 1].push_back({it[2], it[0] - 1});
        }
        vector<int> dp(n, INF);
        dp[n - 1] = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, n - 1});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dp[u])
                continue;
            for (auto [w, v] : adj[u]) {
                int sum = w + d;
                if (sum >= dp[v])
                    continue;
                dp[v] = sum;
                pq.push({sum, v});
            }
        }
        return dp;
    }

public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> distFromN = evaluateDistFromN(n, edges);

        vector<vector<int>> adj(n);

        for (auto& it : edges) {
            int u = it[0] - 1;
            int v = it[1] - 1;

            if (distFromN[u] > distFromN[v])
                adj[u].push_back(v);
            else if (distFromN[v] > distFromN[u])
                adj[v].push_back(u);
        }

        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(),
             [&](int a, int b) { return distFromN[a] > distFromN[b]; });

        vector<int> ways(n);
        ways[0] = 1;

        for (int u : order) {
            for (int v : adj[u]) {
                ways[v] += ways[u];
                if (ways[v] >= MOD)
                    ways[v] -= MOD;
            }
        }

        return ways[n - 1];
    }
};