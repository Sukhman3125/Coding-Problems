class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<long long, int> mp;
        for(int i=0;i<n-1;i++){
            int a = nums[i];
            int b = nums[i+1];
            if(a==b){
                ans++;
                continue;
            }
            int x = min(a,b), y = max(a,b);

            long long key = (static_cast<long long>(x) << 32) |
                            static_cast<unsigned int>(y);
            mp[key]++;
        }
        int best = 0;
        for(auto& [_,f]: mp){
            best = max(best, f);
        }
        return ans + best;
    }
};