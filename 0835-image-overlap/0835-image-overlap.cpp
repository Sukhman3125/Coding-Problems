class Solution {
private:
    int _(vector<vector<int>>& img1, vector<vector<int>>& img2, pair<int,int> p) {
        int cnt = 0;
        auto [up, right] = p;
        int n = img1.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 0) continue;
                int ni = i - up;
                int nj = j + right;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n &&
                    img2[ni][nj] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxi = 0;
        for(int right = -30; right<=30; right++){
            for(int up = -30; up<=30; up++){
                maxi = max(maxi, _(img1, img2, {right,up}));
            }
        }
        return maxi;
    }
};