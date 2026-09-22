class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        vector<int> arr;
        for(auto& it:matrix){
            for(auto x:it){
                arr.push_back(x);
            }
        }
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};