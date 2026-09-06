class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        int nextSpeed = speed[n-1];
        int cnt = 1;
        for(int i=n-2;i>=0;i--){
            if(position[i+1]-position[i] > distance && nextSpeed >= speed[i] ){
                nextSpeed = speed[i];
                cnt++;
            }
        }
        return cnt;
    }
};