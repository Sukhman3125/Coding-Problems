class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it:nums)
            pq.push(it);
        long long ans = 0;
        for(int i=0;i<k;i++){
            int lar = pq.top();
            ans += lar;
            pq.pop();
            pq.push(ceil(lar/3.0));
        }
        return ans;
    }
};