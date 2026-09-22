class Solution {
using p = pair<int,int>;
private:
    static inline int INF = 1e9;
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back({it[2], it[1]});
            adj[it[1]].push_back({2 * it[2], it[0]});
        }

        vector<int> dp(n, INF);
        dp[0] = 0;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(u == n-1) return d;
            for(auto [w, v]:adj[u]){
                int cost = d+w;
                if(cost >= dp[v]) continue;
                dp[v] = cost;
                pq.push({cost, v});
            }
        }
        return -1;
    }
};