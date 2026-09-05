class Solution {
public:
    int maxPower(string s) {
        int f[26] = {0};
        char curr = '\0';
        int streak = 0;
        for(auto it:s){
            if(it==curr){
                streak++;
            }else{
                streak = 1;
                curr = it;
            }
            f[it-'a'] = max(streak, f[it-'a']);
        }
        int maxi = 0;
        for(auto it:f){
            maxi = max(it, maxi);
        }
        return maxi;
    }
};