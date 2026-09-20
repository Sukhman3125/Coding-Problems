class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        int n = nums.size();
        vector<int> perm = nums;
        vector<pair<int,int>> grps;
        grps.push_back({0,n});

        vector<int> ans(15,0);

        for(int b=14;b>=0;b--){
            vector<pair<int,int>> currGrps;
            int pref = 0;
            bool broken = false;
            for(auto [i,j]:grps){
                if(broken){
                    currGrps.push_back({i,j});
                    continue;
                }
                int m = i;
                for(int idx = i; idx < j; idx++){
                    if((perm[idx]>>b)&1){
                        swap(perm[idx], perm[m]);
                        m++;
                    }
                }
                if(m==j){
                    pref = j;
                    currGrps.push_back({i,j});
                }else{
                    pref = m;
                    broken = true;
                    if(i<m) currGrps.push_back({i,m});
                    currGrps.push_back({m,j});
                }
            }
            ans[14-b] = pref;
            grps = currGrps;
        }
        return ans;
    }
};

