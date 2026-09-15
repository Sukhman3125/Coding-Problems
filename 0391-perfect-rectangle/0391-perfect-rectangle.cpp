class Solution {
private:
    pair<int, int> _(string s) {
        int pos = s.find('_');

        return {stoi(s.substr(0, pos)), stoi(s.substr(pos + 1))};
    }

public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<string, int> freq;
        int xMin = INT_MAX, xMax = INT_MIN;
        int yMin = INT_MAX, yMax = INT_MIN;
        long long areaSum = 0;
        for (auto& it : rectangles) {
            int x1 = it[0], y1 = it[1], x2=it[2], y2=it[3];
            freq[to_string(x1) + "_" + to_string(y1)]++;
            freq[to_string(x2) + "_" + to_string(y2)]++;
            freq[to_string(x1) + "_" + to_string(y2)]++;
            freq[to_string(x2) + "_" + to_string(y1)]++;
            xMin = min(xMin, x1);
            yMin = min(yMin, y1);
            xMax = max(xMax, x2);
            yMax = max(yMax, y2);

            areaSum += 1LL*(it[2]-it[0])*(it[3]-it[1]);
        }
        set<pair<int,int>> corners;
        for (auto& [s, f] : freq) {
            if (f == 1){
                corners.insert(_(s));
                if(corners.size() > 4) return false;
            } else if (f%2 == 1) return false;
        }
        if(corners.size()!=4) return false;
        if(
            !corners.contains({xMin,yMin}) ||
            !corners.contains({xMin,yMax}) ||
            !corners.contains({xMax,yMin}) ||
            !corners.contains({xMax,yMax})
        ) return false;

        long long area = 1LL * (xMax-xMin) * (yMax-yMin);
        return area==areaSum;
    }
};