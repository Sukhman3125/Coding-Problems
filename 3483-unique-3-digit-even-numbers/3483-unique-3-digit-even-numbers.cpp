class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int cnt = 0;
        int freq[10] = {0};
        for(auto it:digits) freq[it]++;
        for(int i=100;i<1000;i+=2){
            int reqFreq[10] = {0};
            int _ = i;
            while(_>0){
                reqFreq[_%10]++;
                _/=10;
            }
            bool formed = true;
            for(int i=0;i<10;i++){
                if(freq[i]<reqFreq[i]){
                    formed = false;
                    break;
                }
            }
            if(formed) cnt++;
        }
        return cnt;
    }
};