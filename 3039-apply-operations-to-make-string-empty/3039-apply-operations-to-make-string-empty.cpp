class Solution {
public:
    string lastNonEmptyString(string s) {
        vector<int> idx[26];
        for(int i=0;i<s.size();i++){
            idx[s[i]-'a'].push_back(i);
        }
        for(auto& it:idx){
            reverse(it.begin(), it.end());
        }
        while(1){
            bool hasGreaterThan1 = false;
            for(auto& v:idx) {
                if(v.size() > 1){
                    hasGreaterThan1 = true;
                    break;
                }
            }
            if(!hasGreaterThan1) break;
            for(auto& v:idx){
                if(v.size() == 0)
                    continue;
                s[v.back()] = '\0';
                v.pop_back();
            }
        }
        string ans = "";
        for(auto it:s){
            if(it!='\0') ans += it;
        }
        return ans;
    }
};