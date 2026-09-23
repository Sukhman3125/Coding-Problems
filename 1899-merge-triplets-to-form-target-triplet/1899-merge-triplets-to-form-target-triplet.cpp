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
            
            int achieved = 0;
            for(int j=0;j<3;j++){
                if(triplets[i][j] == target[j]){
                    maxAchieved[j] = true; 
                }
                if(maxAchieved[j]) achieved++;
            }
            if(achieved==3) return true;
        }
        return false;
    }
};