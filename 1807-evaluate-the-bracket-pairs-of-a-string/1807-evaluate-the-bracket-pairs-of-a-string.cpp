class Trie {
private:
    int idx = -1;
    Trie* next[26] = {nullptr};
    void put(char ch) { 
        this->next[ch - 'a'] = new Trie(); 
    }
    Trie* get(char ch) { 
        return this->next[ch - 'a']; 
    }
public:
    void insert(const string& key, int idx){
        Trie* temp = this;
        for(char ch:key){
            
            if(!temp->get(ch)) temp->put(ch);
            temp = temp->get(ch);
        }
        temp->idx = idx;
    }

    int valIdx(const string& word){
        Trie* temp = this;
        for(char ch: word){
            if(!temp->get(ch)) return -1;
            temp = temp->get(ch);
        }
        return temp->idx;
    }
};
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        Trie* dict = new Trie();
        for(int i=0;i<knowledge.size();i++){
            dict->insert(knowledge[i][0], i);
        }
        string key = "";
        bool unresolved = false;
        string ans = "";
        for (auto it : s) {
            if (it == '(')
                unresolved = true;
            else if (it == ')') {
                unresolved = false;
                int idx = dict->valIdx(key);
                if (idx != -1)
                    ans += knowledge[idx][1];
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