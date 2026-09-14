class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto it:nums){
            vector<int> digs;
            while(it){
                digs.push_back(it%10);
                it/=10;
            }
            reverse(digs.begin(), digs.end());
            for(auto x:digs) ans.push_back(x);
        }
        return ans;
    }
};