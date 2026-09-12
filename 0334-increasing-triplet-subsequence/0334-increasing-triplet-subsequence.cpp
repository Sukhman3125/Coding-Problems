class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini = INT_MAX;
        int mini2 = INT_MAX;
        for(auto it:nums){
            if(it<=mini) mini = it;
            else if(it<=mini2) mini2 = it;
            else return true;
        }
        return false;
    }
};