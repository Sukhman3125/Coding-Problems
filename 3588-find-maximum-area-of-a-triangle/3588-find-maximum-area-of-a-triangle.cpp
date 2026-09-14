class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        unordered_map<int,pair<int,int>> yRange;
        unordered_map<int,pair<int,int>> xRange;
        int rightMost = 0;
        int leftMost = INT_MAX;
        int upperMost = 0;
        int downMost = INT_MAX;
        for(auto& it:coords){
            int x = it[0], y = it[1];
            if(yRange.find(x) == yRange.end()){
                yRange[x] = {y,y};
            }else{
                yRange[x].first = min(yRange[x].first, y);
                yRange[x].second = max(yRange[x].second, y);
            }
            if(xRange.find(y) == xRange.end()){
                xRange[y] = {x,x};
            }else{
                xRange[y].first = min(xRange[y].first, x);
                xRange[y].second = max(xRange[y].second, x);
            }
            leftMost = min(leftMost,x);
            rightMost = max(rightMost,x);
            upperMost = max(upperMost,y);
            downMost = min(downMost,y);
        }
        long long ans = -1;
        for(auto& [x,y]:yRange){
            auto [y1,y2] = y;
            long long yLen = y2-y1;
            ans = max({
                ans,
                yLen * (rightMost - x),
                yLen * (x-leftMost)
            });
        }
        for(auto& [y,x]:xRange){
            auto [x1,x2] = x;
            long long xLen = x2-x1;
            ans = max({
                ans,
                xLen * (upperMost - y),
                xLen * (y-downMost)
            });
        }
        return ans == 0?-1:ans;
    }
};