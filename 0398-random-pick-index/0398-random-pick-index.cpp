class Solution {
    unordered_map<int,vector<int>> idx; 
public:
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            idx[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int n = idx[target].size();
        int i = rand()%n;
        return idx[target][i];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */