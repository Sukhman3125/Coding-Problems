class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        vector<int> stck;
        long long ans = 0;
        for(auto it:nums){
            while(!stck.empty() && stck.back()>it){
                stck.pop_back();
            }
            ans += lower_bound(stck.begin(), stck.end(), it) - stck.begin();
            stck.push_back(it);
        }
        return ans;
    }
};