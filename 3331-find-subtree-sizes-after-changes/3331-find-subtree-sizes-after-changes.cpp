
class Solution {
private:
    void dfs(int u, vector<vector<int>>& adj, string& s, int prev[26], vector<int>& parent) {
        int c = s[u] - 'a';
        int old = prev[c];
        if (old != -1)
            parent[u] = old;
        prev[c] = u;
        for (int v : adj[u])
            dfs(v, adj, s, prev, parent);
        prev[c] = old;
    }

    int calc(int u, vector<vector<int>>& adj, vector<int>& ans) {
        ans[u] = 1;
        for (int v : adj[u])
            ans[u] += calc(v, adj, ans);
        return ans[u];
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        int prev[26];
        fill(prev, prev + 26, -1);
        dfs(0, adj, s, prev, parent);

        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; i++)
            finalAdj[parent[i]].push_back(i);

        vector<int> ans(n);
        calc(0, finalAdj, ans);

        return ans;
    }
};
