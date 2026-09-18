class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0;
        for(int i=1;;i++){
            bool found = false;
            for(auto it:arr){
                if(it == i){
                    found = true;
                    break;
                }
            }
            if(!found) cnt++;
            if(cnt == k) return i;
        }
        return -1; // dead code
    }
};