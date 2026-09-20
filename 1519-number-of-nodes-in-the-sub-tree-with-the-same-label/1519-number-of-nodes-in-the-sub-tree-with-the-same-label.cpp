class Solution {
private:
    vector<vector<int>> tree;
    vector<int> ans;
    vector<int> recur(string& labels, int node = 0,int par = -1) {
        vector<int> lbs(26,0);
        for(auto it:tree[node]){
            if(it==par) continue;
            vector<int> curr = recur(labels, it, node);
            for(int i=0;i<26;i++){
                lbs[i] += curr[i];
            } 
        }
        ans[node] = ++lbs[labels[node]-'a'];
        return lbs;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string& labels) {
        tree.resize(n);
        ans.resize(n);
        for(auto it:edges){
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }
        recur(labels);
        return ans;
    }
};