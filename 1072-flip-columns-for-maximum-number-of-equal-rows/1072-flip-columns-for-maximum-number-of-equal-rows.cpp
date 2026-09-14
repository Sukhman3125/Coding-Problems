class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string,int> freq;
        for(auto& it:matrix){
            string s;           
            for(auto& x:it){
                s += to_string(x);
            }
            if(s[0] == '0'){
                for(auto& ch:s){
                    if(ch=='1') ch='0';
                    else ch='1';
                }
            }
            freq[s]++;
        }
        int maxi = 0;
        for(auto [_,f]:freq){
            maxi = max(maxi,f);
        }
        return maxi;
    }
};