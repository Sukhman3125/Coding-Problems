class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,long long>> pref(n,{0,0});
        unordered_map<int,pair<int,long long>> cnt_sum;
        for(int i=0;i<n;i++){
            cnt_sum[nums[i]].first++;
            cnt_sum[nums[i]].second += i;
            pref[i] = cnt_sum[nums[i]];
        }
        vector<pair<int,long long>> suff(n,{0,0});
        cnt_sum.clear();
        for(int i=n-1;i>=0;i--){
            cnt_sum[nums[i]].first++;
            cnt_sum[nums[i]].second += i;
            suff[i] = cnt_sum[nums[i]];
        }
        vector<long long> arr(n);
        for(int i=0;i<n;i++){
            auto [prefCnt, prefSum] = pref[i]; 
            auto [suffCnt, suffSum] = suff[i]; 
            prefCnt--, prefSum-=i;
            suffCnt--, suffSum-=i;
            arr[i] = 1LL*i*prefCnt - prefSum + suffSum - 1LL*i*suffCnt;
        }
        return arr;
    }
};