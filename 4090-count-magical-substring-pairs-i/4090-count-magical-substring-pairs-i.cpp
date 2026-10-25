class Solution {
public:
    int countMagicalPairs(string s) {
        int n = s.size();
        long long ans = 0;
        for(int j=0; j<n-1; j++){
            vector<int> left(27,0), right(27,0);
            int distinct = 0;
            vector<int> L(j+1);
            for(int i=j;i>=0;i--){
                if(left[s[i]-'a']++ == 0)
                    distinct++;
                L[i] = distinct;
            }
            distinct = 0;
            vector<int> R(n-j-1);

            for(int k=j+1;k<n;k++){
                if(right[s[k]-'a']++ == 0)
                    distinct++;
                R[k-j-1] = distinct;
            }
            vector<int> freq(27,0);
            for(int i=0;i<=j;i++)
                freq[L[i]]++;
            for(int k=j+1;k<n;k++)
                ans += freq[R[k-j-1]];
        }
        return ans;
    }
};