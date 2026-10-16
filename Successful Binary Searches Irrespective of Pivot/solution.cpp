class Solution {
  public:
    int countAlwaysFound(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefMax(n), suffMin(n);
        prefMax[0] = arr[0];
        suffMin[n-1] = arr[n-1];
        for(int i=1; i<n; i++){
            prefMax[i] = max(prefMax[i-1], arr[i]);
            suffMin[n-i-1] = min(suffMin[n-i], arr[n-i-1]);
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(prefMax[i] == arr[i] && suffMin[i] == arr[i]) ans++;
        }
        return ans;
    }
};