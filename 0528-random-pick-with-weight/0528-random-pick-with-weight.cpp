class Solution {
private:
    vector<int> cumSum;
public:
    Solution(vector<int>& w) {
        int n = w.size();
        cumSum.resize(n);
        cumSum[0] = w[0];
        for(int i=1;i<n;i++){
            cumSum[i] = w[i] + cumSum[i-1];
        }
        srand(0);
    }

    int pickIndex() {
        int random = rand()%cumSum.back() + 1;
        int l = 0;
        int r = cumSum.size()-1;
        int ans;
        while(l<=r){
            int m = l + (r-l)/2;
            if(cumSum[m]>=random){
                r = m-1;
                ans = m;
            }else{
                l = m+1;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */