class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int n = nums.size();
        int size = 0;
        int i=0;
        while(i<n){
            size++;
            int target = nums[i];
            while(i<n && nums[i] == target) i++;
        }
        return n-size;
    }
};