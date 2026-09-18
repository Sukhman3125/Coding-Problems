class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int cnt = 0;
        for(auto& it:grid){
            for(auto& x:it){
                if(x<0)cnt++;
            }
        }
        return cnt;
    }
};