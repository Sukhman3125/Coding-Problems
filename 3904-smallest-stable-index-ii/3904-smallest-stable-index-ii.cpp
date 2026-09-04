class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n,nums[0]);
        vector<int> suff(n,nums.back());
        for(int i=1;i<n;i++){
            pref[i] = max(pref[i-1],nums[i]);
            suff[n-i-1] = min(suff[n-i], nums[n-i-1]);
        }
        for(int i=0;i<n;i++){
            if(pref[i]-suff[i]<=k) return i;
        }
        return -1;
    }
};