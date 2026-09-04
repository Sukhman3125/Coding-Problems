class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int sum = 0;
        int i=0, j=0;
        vector<int> temp = arr;
        arr.insert(arr.end(), temp.begin(), temp.end());
        while(j<m){
            sum += arr[j];
            j++;
        }
        int ans = sum;
        while(j<arr.size()){
            sum += arr[j];
            sum -= arr[i];
            ans = max(ans,sum);
            i++,j++;
        }
        return ans;
    }
};