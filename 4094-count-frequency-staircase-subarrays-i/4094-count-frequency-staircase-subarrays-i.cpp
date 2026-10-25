class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            unordered_map<int, pair<int,int>> freq; //order, freq
            int k = 1, unbalanced = 0;
            for(int j=i;j<n;j++){
                if(freq.contains(nums[j])){
                    freq[nums[j]].second++;
                }else{
                    freq[nums[j]].first = k++;
                    freq[nums[j]].second = 1;
                    unbalanced++;
                }
                if(freq[nums[j]].first == freq[nums[j]].second)
                    unbalanced--;
                if(freq[nums[j]].first < freq[nums[j]].second)
                    break;
                if(unbalanced == 0)
                    cnt++;
            }
        }
        return cnt;
    }
};