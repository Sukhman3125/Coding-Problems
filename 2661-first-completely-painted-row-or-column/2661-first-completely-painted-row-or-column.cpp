class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> idx(m*n+1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                idx[mat[i][j]] = {i,j};
            }
        }
        vector<int> rowCnt(m,0);
        vector<int> colCnt(n,0);
        for(int k=0;k<arr.size();k++){
            auto [i,j] = idx[arr[k]];
            if(++rowCnt[i] == n || ++colCnt[j] == m) return k;
        }
        return -1; // dead code
    }
};