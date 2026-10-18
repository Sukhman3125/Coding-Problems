class Solution {
public:
    int minSelection(vector<vector<int>>& ava, vector<vector<int>>& tar) {
        sort(tar.begin(), tar.end());

        vector<vector<int>> merged;

        for(auto& it: tar){
            if(merged.empty() || it[0] > merged.back()[1]) merged.push_back(it);
            else merged.back()[1] = max(merged.back()[1], it[1]);
        }

        sort(ava.begin(), ava.end());
        int n = ava.size();
        int ans = 0, idx = 0, best = 0, reach = 0;

        for(auto& it: merged){
            int l = it[0], r = it[1];
            if(reach < l){
                while(idx < n && ava[idx][0] <= l){
                    best = max(best, ava[idx][1]);
                    idx++;
                }
                if(best < l) return -1;
                reach = best;
                ans++;
            }
            while(reach< r){
                while(idx < n && ava[idx][0] <= reach){
                    best = max(best, ava[idx][1]);
                    idx++;
                }
                if(best <= reach) return -1;
                reach = best;
                ans++;
            }
        }
        return ans;
    }
};