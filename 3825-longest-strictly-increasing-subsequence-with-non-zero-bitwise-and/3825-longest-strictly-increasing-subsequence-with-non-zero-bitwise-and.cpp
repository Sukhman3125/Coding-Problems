class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int b=0; b<32;b++){
            vector<int> temp;
            for(int i=0; i<n; i++){
                if((nums[i] & (1<<b)) == 0 ) continue;
                auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                if(it == temp.end()){
                    temp.push_back(nums[i]);
                }else{
                    *it = nums[i];
                }
            }
            ans = max(ans, (int)temp.size());
        }
        return ans;
    }
};