class Solution {
using t = tuple<int,int,int>; 
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        priority_queue<t, vector<t>, greater<t>> pq;
        pq.push({0, src, 0});
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;
        while (!pq.empty()) {
            auto [cost, curr, stops] = pq.top();
            pq.pop();
            if (curr == dst)
                return cost;
            if (stops == k + 1)
                continue;
            for (auto [next, price] : adj[curr]) {
                int newCost = cost + price;
                if (newCost < dist[next][stops + 1]) {
                    dist[next][stops + 1] = newCost;
                    pq.push({newCost, next, stops + 1});
                }
            }
        }
        return -1;
    }
};