class Trie{
public:
    Trie* next[26] = {nullptr};
    bool isWord = false;
    string word = "";

    void put(char ch){
        next[ch-'a'] = new Trie();
    }

    Trie* get(char ch){
        return next[ch-'a'];
    }

    void dfs(vector<string>& ans){
        if(ans.size() == 3) return;

        if(isWord){
            ans.push_back(word);
        }

        for(int i = 0; i < 26 && ans.size() < 3; i++){
            if(next[i]){
                next[i]->dfs(ans);
            }
        }
    }

    void insert(string& s){
        Trie* node = this;

        for(auto ch : s){
            if(!node->get(ch))
                node->put(ch);

            node = node->get(ch);
        }

        node->isWord = true;
        node->word = s;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* trie = new Trie();
        for(auto it:products){
            trie->insert(it);
        }
        vector<vector<string>> ans;
        for(auto it:searchWord){
            if(trie) 
                trie = trie->get(it);
            vector<string> curr;
            if(trie)
                trie->dfs(curr);
            ans.push_back(curr);
        }
        return ans;
    }
};