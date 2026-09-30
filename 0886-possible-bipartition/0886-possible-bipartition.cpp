class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);

        for (auto &e : dislikes) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int nxt : adj[curr]) {
                    if (color[nxt] == -1) {
                        color[nxt] = color[curr] ^ 1;
                        q.push(nxt);
                    }
                    else if (color[nxt] == color[curr]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};