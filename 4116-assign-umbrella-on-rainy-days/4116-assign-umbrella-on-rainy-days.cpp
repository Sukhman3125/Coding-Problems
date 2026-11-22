
class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string> ans;
        int cnt = 0; 

        for(int i = 0; i < n; i++) {
            bool alice = i < n-1 && rain[i] == 1 && rain[i+1] == 1;
            bool bob = rain[i] == 1;

            if(alice && !bob) {
                ans.push_back("Alice");
                cnt++;
            }
            else if(bob && !alice) {
                ans.push_back("Bob");
                cnt--;
            }
            else if(!alice && !bob) {
                ans.push_back("None");
            }
            else if(cnt > 0) {
                ans.push_back("Bob");
                cnt--;
            }
            else {
                ans.push_back("Alice");
                cnt++;
            }
        }

        return ans;
    }
};
