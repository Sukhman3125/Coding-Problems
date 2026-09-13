class Solution {
private:
    struct Fen{
        int n;
        vector<long long> bit;
        Fen(int n){
            this->n = n;
            bit = vector<long long>(n+1, 0);
        }
        void add(int idx, long long val){
            for(;idx<=n;idx += idx & (-idx)) bit[idx] += val;
        }
        long long sum(int idx){
            long long res = 0;
            for(;idx>0;idx -= idx & (-idx)) res += bit[idx];
            return res;
        }
    };
public:
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int n = nums.size();
        if(k==0)
            return 1LL*n*(n+1)/2;
        vector<long long> pref(n+1, 0);
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i] + nums[i];
        }

        vector<long long> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fen ft(vals.size());
        auto getIdx = [&](long long it){
            return int(lower_bound(vals.begin(), vals.end(), it) - vals.begin() + 1);
        };
        long long ans = 0;
        ft.add(getIdx(pref[0]), 1);

        for(int j=1;j<=n;j++){
            long long x = pref[j];
            long long leftLmt = x-goal-k;
            long long rightLmt = x-goal+k;
            int posLeft = upper_bound(vals.begin(),vals.end(), leftLmt) - vals.begin();
            long long leftCnt = ft.sum(posLeft);
            int posRight = lower_bound(vals.begin(),vals.end(), rightLmt) - vals.begin();
            long long total = j;
            long long lessThanRight = ft.sum(posRight);
            long long rightCnt = total-lessThanRight;
            ans += leftCnt + rightCnt;
            ft.add(getIdx(x), 1);
        }
        return ans;
    }
};