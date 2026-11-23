class Solution {
private:
    bool tryDist(vector<int>& position, int n, int k){
        int prev = -1e9;
        for(auto it:position){
            if(it-prev >= k){
                n--;
                prev = it;
            }if(n==0)
                return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int n) {
        sort(position.begin(), position.end());
        int l = 0;
        int r = position.back();
        int ans;
        while(l<=r){
            int m = l + (r-l)/2;
            if(tryDist(position, n, m)){
                ans = m;
                l = m+1;
            }else
                r = m-1;
        }
        return ans;
    }
};