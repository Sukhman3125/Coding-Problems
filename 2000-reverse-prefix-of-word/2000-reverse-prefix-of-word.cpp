class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0, j = 0, n = word.size();
        while(j<n && word[j] != ch) j++;
        if(j==n) return word;
        for(;i<j;i++,j--) swap(word[i], word[j]);
        return word;
    }
};