class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it:arr){
            maxi = max(maxi, it);
            mini = min(mini, it);
        }
        return {mini, maxi};
    }
};