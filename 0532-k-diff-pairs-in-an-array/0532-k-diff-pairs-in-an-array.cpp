class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(k==0) {
            unordered_map<int, int> freq;
            for(auto it:nums) freq[it]++;
            int cnt = 0;
            for(auto [x,f]: freq){
                if(f>1) cnt++;
            }
            return cnt;
        }
        unordered_set<int> st;
        for(auto it:nums){
            st.insert(it);
        }
        int ans = 0;
        for(auto it:st){
            if(st.contains(it+k)) ans++;
        }
        return ans;
    }
};