class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> f;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            f[nums[i]].push_back(i);
        }
        int cnt = 0;
        for(auto& [x,v]:f){
            if(v.size()!=3) continue;
            if(v[2]-v[1] == v[1]-v[0]) cnt++;
        }
        return cnt;
    }
};