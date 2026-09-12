class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        for(int i=0;i<=n;i++){
            int _ = i;
            int cnt = 0;
            while(_){
                if(_&1) cnt++;
                _>>=1;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};