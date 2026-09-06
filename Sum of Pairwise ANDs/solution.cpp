class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        long long ans = 0;
        for(int i=0;i<32;i++){
            int cnt = 0;
            int tar = 1<<i;
            for(auto it:arr){
                if((it&tar)!=0) cnt++;
            }
            ans += 1LL*cnt*(cnt-1)/2*(1LL<<i);
        }
        return ans;
    }
};