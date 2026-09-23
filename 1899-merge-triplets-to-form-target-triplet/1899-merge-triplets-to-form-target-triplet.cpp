class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool maxAchieved[3] = {false};
        for(int i=0;i<triplets.size();i++){
            bool valid = true;
            for(int j=0;j<3;j++){
                if(triplets[i][j] > target[j]){
                    valid = false; 
                    break;
                }
            }
            if(!valid) continue;
            for(int j=0;j<3;j++){
                if(triplets[i][j] == target[j]){
                    maxAchieved[j] = true; 
                }
            }
        }
        for(auto ach:maxAchieved){
            if(!ach) return false;
        }
        return true;
    }
};