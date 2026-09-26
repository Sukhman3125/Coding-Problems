class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for(auto& it:knowledge) mp[it[0]] = it[1];
        string key = "";
        bool unresolved = false;
        string ans = "";
        for(auto it:s){
            if(it=='(') unresolved = true;
            else if(it==')'){
                unresolved = false;
                if(mp.contains(key)) ans += mp[key];
                else ans += '?';
                key = "";
            }else if(unresolved){
                key += it;
            }else{
                ans += it;
            }
        }
        return ans;
    }
};