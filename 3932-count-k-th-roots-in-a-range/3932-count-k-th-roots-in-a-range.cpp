class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1) {
            return r-l+1;
        }
        int ans = 0;
        for(int i=0;;i++){
            int curr = pow(i,k);
            if(curr>=l && curr<=r) ans++;
            else if(curr>r) break;
        }
        return ans;
    }
};