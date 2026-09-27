class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        while(1){
            set<int> st;
            bool empty = true;
            for(auto& it:nums){
                if(it==-1) continue;
                empty = false;
                if(st.contains(it)) continue;
                st.insert(it);
                it = -1;
            }
            for(auto it:st){
                ans.push_back(it);
            }
            if(empty) break;
        }
        return ans;
    }
};