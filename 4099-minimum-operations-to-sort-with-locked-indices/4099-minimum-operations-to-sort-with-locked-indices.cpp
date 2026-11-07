class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        long long cost = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            if(locked[i] == 0)
                continue;
            if(nums[i] != i+1 || maxi != i+1){
                cost++;
                if(cost > k) return -1;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i] > nums[j])
                    cost++;
            }
        }
        return cost;
    }
};