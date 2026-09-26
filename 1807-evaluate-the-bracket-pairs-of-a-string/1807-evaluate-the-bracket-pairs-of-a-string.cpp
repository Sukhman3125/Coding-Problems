class Trie {
private:
    string val = "";
    Trie* next[26] = {nullptr};
    void put(char ch) { 
        this->next[ch - 'a'] = new Trie(); 
    }
    Trie* get(char ch) { 
        return this->next[ch - 'a']; 
    }
public:
    void insert(string key, string val){
        Trie* temp = this;
        for(char ch:key){
            if(!temp->get(ch)) temp->put(ch);
            temp = temp->get(ch);
        }
        temp->val = val;
    }

    string value(string word){
        Trie* temp = this;
        for(char ch: word){
            if(!temp->get(ch)) return "";
            temp = temp->get(ch);
        }
        return temp->val;
    }
};
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        Trie* dict = new Trie();
        for (auto& it : knowledge)
            dict->insert(it[0], it[1]);
        string key = "";
        bool unresolved = false;
        string ans = "";
        for (auto it : s) {
            if (it == '(')
                unresolved = true;
            else if (it == ')') {
                unresolved = false;
                string val = dict->value(key);
                if (val != "")
                    ans += val;
                else
                    ans += '?';
                key = "";
            } else if (unresolved) {
                key += it;
            } else {
                ans += it;
            }
        }
        return ans;
    }
};