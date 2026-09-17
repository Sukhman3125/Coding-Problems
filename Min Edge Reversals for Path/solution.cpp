class Solution {
  using p = pair<int,int>;
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        vector<vector<p>> adj(n);
        for(auto& it:edges){
            adj[it[0]-1].push_back({0, it[1]-1});
            adj[it[1]-1].push_back({1, it[0]-1});
        }
        src = src-1, dst = dst-1;
        int inf = 1e9;
        vector<int> dp(n, inf);
        priority_queue<p, vector<p>, greater<p>> pq;
        dp[src] = 0;
        pq.push({0,src});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d != dp[u]) continue;
            if(u == dst) return d;
            for(auto [w, v]:adj[u]){
                if(d+w<dp[v]){
                    dp[v] = d+w;
                    pq.push({dp[v], v});
                }
            }
        }
        return -1;
    }
};