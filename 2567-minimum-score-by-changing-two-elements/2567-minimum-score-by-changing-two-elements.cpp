class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int> sml;
        priority_queue<int, vector<int>, greater<int>> lar;
        for(auto it:nums){
            sml.push(it);
            lar.push(it);
            if(sml.size() > 3)
                sml.pop();
            if(lar.size() > 3)
                lar.pop();
        }
        int l[3], s[3];     
        // l[0] is 3rd largest, l[1] is 2nd largest and l[0] is largest
        // s[0] is 3rd smallest, s[1] is 2nd smallest and s[0] is smallest
        for(int i=0;i<3;i++){
            l[i] = lar.top();
            s[i] = sml.top();
            lar.pop(), sml.pop();
        }
        return min({
            l[0] - s[2],
            l[1] - s[1],
            l[2] - s[0]
        });
    }
};