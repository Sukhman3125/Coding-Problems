class Solution {
private:
    int scoreOf(string& word, vector<int>& score){
        int ans = 0;
        for(auto it:word) ans += score[it-'a'];
        return ans;
    }
    int helper(vector<string>& words, vector<int> f, vector<int>& score, int i = 0, int curr = 0){
        if(i==words.size()){
            return curr;
        }

        // not take
        int notTake = helper(words, f, score, i+1, curr);
        
        // take
        for(auto it:words[i]){
            if(f[it-'a']==0) return notTake;
            f[it-'a']--;
        }
        int take = helper(words, f, score,i+1, curr + scoreOf(words[i], score));

        return max(take, notTake);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> f(26,0);
        for(auto it:letters) f[it-'a']++;
        return helper(words, f, score);
    }
};