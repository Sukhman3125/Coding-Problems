class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(), v.end(), [](const int& a, const int& b){
            return a>b;
        });
        int n = v.size();
        int pref = 0, ans = 0;
        for(int i=0; i<n; i++){
            pref += v[i];
            if(pref < 0)
                break;
            ans += pref;
        }
        return ans;
    }
};