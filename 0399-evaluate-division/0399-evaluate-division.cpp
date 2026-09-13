class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];

            adj[a].push_back({b, values[i]});
            adj[b].push_back({a, 1.0/values[i]});
        }
        vector<double> ans;
        for(auto& query:queries){
            string a = query[0], b = query[1];
            if(adj.find(a) == adj.end() || adj.find(b) == adj.end()) {
                ans.push_back(-1);
                continue;
            }
            double curr = -1;
            unordered_set<string> vis;
            queue<pair<string,double>> q;
            vis.insert(a);
            q.push({a,1});
            while(!q.empty()){
                auto [s,val] = q.front();
                q.pop();
                if(s == b) {
                    curr = val;
                    break;
                }
                for(auto [next, nextVal]:adj[s]){
                    if(vis.contains(next)) continue;
                    vis.insert(next);
                    q.push({next, val*nextVal});
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};