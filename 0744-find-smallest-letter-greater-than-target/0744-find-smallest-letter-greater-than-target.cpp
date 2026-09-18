class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size()-1;
        if(letters.back() <= target) return letters[0];
        int ans = INT_MAX;
        while(l<=r){
            int m = l+(r-l)/2;
            if(letters[m]<=target){
                l = m+1;
            }else{
                ans = min(ans,m);
                r = m-1;
            }
        }
        return letters[ans];
    }
};