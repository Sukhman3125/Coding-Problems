class Solution {
public:
    int mirrorFrequency(string s) {
        int f[36] = {0};
        for(auto it:s){
            if(isdigit(it)){
                f[it-'0']++;
            }else{
                f[it-'a'+10]++;
            }
        }
        int ans = 0;
        for(char ch='a';ch<='m';ch++){
            ans += abs(f[ch-'a'+10] - f[25-(ch-'a')+10]);
        }
        for(int i=0;i<=4;i++){
            ans += abs(f[i]-f[9-i]);
        }
        return ans;
    }
};