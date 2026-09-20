class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = 0;
        int prev = INT_MIN;
        for(int i=0;i<target.size();i++){
            if(target[i] < prev){
                ans += prev - target[i];
            }
            prev = target[i];
        }
        ans += target.back();
        return ans;
    }
};