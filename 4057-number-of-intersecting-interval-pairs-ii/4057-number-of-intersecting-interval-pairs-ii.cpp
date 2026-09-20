class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> fir(n), sec(n);
        for(int i=0;i<n;i++){
            fir[i] = v[i][0], sec[i] = v[i][1];
        }
        sort(fir.begin(), fir.end());
        sort(sec.begin(), sec.end());

        long long cnt = 0;
        long long j = 0;
        
        for(int i=0;i<n;i++){
            while(j < n && sec[j] < fir[i]) j++;
            cnt += i-j;
        }
        return cnt;
    }
};