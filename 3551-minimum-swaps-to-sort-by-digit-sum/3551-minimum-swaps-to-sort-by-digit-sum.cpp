class Solution {
private:
    int dSum(int x){
        int sum = 0;
        while(x){
            sum += x%10;
            x /= 10;
        }
        return sum;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> valIdx(n);
        for(int i=0; i<n; i++){
            valIdx[i] = {i, nums[i]};
        }
        sort(valIdx.begin(), valIdx.end(), [&](const auto& a, const auto& b){
            int sA = dSum(a.second), sB = dSum(b.second);
            if(sA == sB) return a.second < b.second;
            return sA < sB;
        });

        vector<int> adj(n);
        for(int i=0; i<n; i++){
            adj[valIdx[i].first] = i;
        }

        vector<bool> vis(n, false);
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(vis[i]) continue;
            cnt++;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                j = adj[j];
            }
        }
        return n-cnt;
    }
};