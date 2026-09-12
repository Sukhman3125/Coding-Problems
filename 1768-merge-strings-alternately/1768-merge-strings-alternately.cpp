class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int n= word1.size()<word2.size()?word1.size():word2.size();
        
        bool _1or2 = word1.size()>word2.size();
        
        string ans="";
        int i;
        for(i=0;i<n;i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        
        if(_1or2){
            for(int j=i;j<word1.size();j++){
                ans+=word1[j];
            }
        }else{
            for(int j=i;j<word2.size();j++){
                ans+=word2[j];
            }
        }
        return ans;
    }
};