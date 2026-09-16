class Solution {
public:
    int minimumOperations(string num) {
        int n = num.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x = (num[i]-'0') * 10 + (num[j]-'0');
                if(x%25 == 0){
                    ans = min(ans, n-i-2);
                }
            }
        }
        if(ans==INT_MAX){
            for(auto it:num) if(it=='0') return n-1;
            return n;
        }
        return ans;
    }
};