class Solution {
    static inline int assigned[8] = {0};
public:
    int distributeCookies(vector<int>& cookies, int k, int i=0) {
        int n = cookies.size();
        if(i == 0)
            for(auto& it:assigned)
                it = 0;
        if(i == n){
            int maxi = 0;
            for(auto it:assigned)
                maxi = max(it, maxi);
            return maxi;
        }
        int best = INT_MAX;
        for(int j=0;j<k;j++){
            assigned[j] += cookies[i];
            best = min(best, distributeCookies(cookies, k, i+1));
            assigned[j] -= cookies[i];
        }
        return best;
    }
};