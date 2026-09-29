class Solution {
private:
    bool isPalin(string& a, int i, int j){
        while(i<j){
            if(a[i]!=a[j]) return false;
            i++, j--;
        }
        return true;
    }
    bool helper(string& a, string& b){
        int i = 0, j = b.size()-1;
        while(1){
            if(a[i]!=b[j]) 
                break;
            i++, j--;
            if(i>j) return true;
        }
        // unmatched i to j
        return isPalin(a, i, j) || isPalin(b, i, j);
    }
public:
    bool checkPalindromeFormation(string& a, string& b) {
        return helper(a, b) || helper(b, a);
    }
};