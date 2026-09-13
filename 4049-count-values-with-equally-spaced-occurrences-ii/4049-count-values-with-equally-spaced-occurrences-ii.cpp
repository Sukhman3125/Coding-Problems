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
            if(v.size()<3) continue;
            bool _ = true;
            int target = v[1]-v[0];
            for(int i=1;i<v.size();i++){
                if(v[i]-v[i-1] != target){
                    _ = false;
                    break;
                }
            }
            if(_) cnt++;
        }
        return cnt;
    }
};