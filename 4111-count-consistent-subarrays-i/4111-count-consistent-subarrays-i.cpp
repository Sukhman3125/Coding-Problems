class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            int mini = nums[i], _and = nums[i];  
            for(int j=i;j<n;j++){
                mini = min(mini, nums[j]);
                _and &= nums[j];
                if(mini == _and)
                    cnt++;
            }
        }
        return cnt;
    }
};