
class Solution {
private:
    void dfs(vector<vector<int>>& adj, string& s, int prev[26], vector<int>& parent, int i=0) {
        int temp = prev[s[i]-'a'];
        if (temp != -1)
            parent[i] = temp;
        prev[s[i]-'a'] = i;
        for (int it : adj[i])
            dfs(adj, s, prev, parent, it);
        prev[s[i]-'a'] = temp;
    }

    int subtreeSize(int u, vector<vector<int>>& adj, vector<int>& ans) {
        ans[u] = 1;
        for (int v : adj[u])
            ans[u] += subtreeSize(v, adj, ans);
        return ans[u];
    }

public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        int prev[26];
        for(int i=0;i<26;i++)
            prev[i] = -1;
        dfs(adj, s, prev, parent);

        vector<vector<int>> finalAdj(n);
        for (int i = 1; i < n; i++)
            finalAdj[parent[i]].push_back(i);

        vector<int> ans(n);
        subtreeSize(0, finalAdj, ans);

        return ans;
    }
};
