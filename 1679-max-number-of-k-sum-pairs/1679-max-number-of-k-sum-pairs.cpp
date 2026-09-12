class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto it:nums) freq[it]++;
        int ans = 0;
        for(auto [x,f]:freq){
            cout << x << " : " << f << '\n';
            if(x>k-x) continue;
            if(x==k-x){
                ans += f/2;
                continue;
            }
            if(freq.find(k-x) != freq.end())
                ans += min(f, freq[k-x]);
        }
        return ans;
    }
};