class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& v) {
        int cnt = 0;
        int n = v.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(max(v[i][0], v[j][0]) <= min(v[i][1], v[j][1])) cnt++;
            }
        }
        return cnt;
    }
};