class Solution {
public:
    bool _(char c){
        const string V = "aAeEiIoOuU";
        return V.contains(c);
    }
    string reverseVowels(string s) {
        int n = s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            while(i<n && !_(s[i])){
                i++;
            }
            while(j>=0 && !_(s[j])){
                j--;
            }
            if(i>=n || j<0) break;
            if(i>=j) break;
            swap(s[i],s[j]);
            i++, j--;
        }
        return s;
    }
};