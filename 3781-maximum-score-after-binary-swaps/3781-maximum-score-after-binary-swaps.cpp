class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        priority_queue<int> pq;
        int n = s.size();
        long long sum = 0;
        for(int i=0; i<n;i++){
            pq.push(nums[i]);
            if(s[i]=='1'){
                sum += pq.top();
                pq.pop();
            }
        }
        return sum;
    }
};