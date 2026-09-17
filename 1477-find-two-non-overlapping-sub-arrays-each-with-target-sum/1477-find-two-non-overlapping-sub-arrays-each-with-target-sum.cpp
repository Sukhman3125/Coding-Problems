class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int inf = 1e9;
        int n = arr.size();
        int i=0, j=0;
        int sum = 0;
        vector<int> pref(n, inf);
        while(j<n){
            sum += arr[j];
            while(sum>target){
                sum -= arr[i];
                i++;
            }
            if(sum == target){
                if(j!=0) pref[j] = min(pref[j-1], j-i+1);
                else pref[j] = j-i+1;
            }else if (j!=0) pref[j] = pref[j-1];
            j++;
        }
        i=n-1, j=n-1;
        sum = 0;
        vector<int> suff(n, inf);
        while(j>=0){
            sum += arr[j];
            while(sum>target){
                sum -= arr[i];
                i--;
            }
            if(sum == target){
                if(j!=n-1) suff[j] = min(suff[j+1], i-j+1);
                else suff[j] = j-i+1;
            }else if (j!=n-1) suff[j] = suff[j+1];
            j--;
        }
        int ans = inf;
        for(int i=1;i<n;i++){
            ans = min(pref[i-1] + suff[i], ans);
        }
        return ans == inf? -1:ans;
    }
};