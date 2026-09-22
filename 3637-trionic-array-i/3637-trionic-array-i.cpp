class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) return false;
            if(state==0){
                if(nums[i] < nums[i-1]) {
                    if (i == 1) return false;
                    state = 1;
                }
            }else if(state==1){
                if(nums[i] > nums[i-1]) state = 2;
            }else if(state==2){
                if(nums[i] < nums[i-1]) return false;
            }
        }
        return state==2;
    }
};