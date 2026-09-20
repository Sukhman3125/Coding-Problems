class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const int MOD = 1e9 + 7;
        int n = conversions.size()+1;
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:conversions){
            adj[it[0]].push_back({it[2], it[1]});
        }
        vector<int> ans(n);
        queue<pair<int,int>> q;
        q.push({1, 0});
        while(!q.empty()){
            auto [w, i] = q.front();
            q.pop();
            ans[i] = w;
            for(auto [_w, _i]: adj[i]){
                long long prod = (1LL*w*_w)%MOD;
                q.push({prod, _i});
            }
        }
        return ans;
    }
};