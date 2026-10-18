class Solution {
private:
    int colorId(char c){
        if(c=='R') return 0;
        if(c=='B') return 1;
        return 2;
    }
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        int n = colors.size();
        vector<int> deg(n, 0);
        vector<int> inDeg(n, 0);
        for(auto& it: edges){
            deg[it[0]]++;
            deg[it[1]]++;
        }
        for(auto& it: edges){
            int u = it[0], v = it[1];

            int colU = colorId(colors[u]);
            int colV = colorId(colors[v]);

            int diff = (colV - colU + 3)%3;

            if(diff == 0) return -1;
            if(diff == 1) inDeg[v]++;
            else inDeg[u]++;
        }

        int root = -1;
        for(int i=0; i<n; i++){
            if(inDeg[i] == 0){
                if(root != -1)
                    return -1;
                root = i;
            }else if( inDeg[i] != 1)
                return -1;
        }

        if(root == -1 || deg[root] > 2)
            return -1;

        return root;
    }
};