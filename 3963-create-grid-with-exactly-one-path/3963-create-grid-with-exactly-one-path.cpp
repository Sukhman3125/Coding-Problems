class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m);
        for(auto& it:grid){
            it = ".";
            for(int i=0;i<n-1;i++){
                it += '#';
            }
        }
        for(auto& ch: grid.back()){
            ch = '.';
        }
        return grid;
    }
};