class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int ans = -1;
        for (auto p1 : points) {
            for (auto p2 : points) {
                int x1 = p1[0], y1 = p1[1];
                int x2 = p2[0], y2 = p2[1];
                if (x1 == x2 || y1 == y2)
                    continue;
                bool found_x1y2 = false;
                bool found_x2y1 = false;
                bool anomally = false;
                for (auto p : points) {
                    int x = p[0], y = p[1];
                    if (x == x1 && y == y2) {
                        found_x1y2 = true;
                        continue;
                    }
                    if (x == x2 && y == y1) {
                        found_x2y1 = true;
                        continue;
                    }
                    if ((x == x1 && y < max(y1, y2) && y > min(y1, y2)) ||
                        (x == x2 && y < max(y1, y2) && y > min(y1, y2)) ||
                        (y == y1 && x < max(x1, x2) && x > min(x1, x2)) ||
                        (y == y2 && x < max(x1, x2) && x > min(x1, x2)) ||
                        (x > min(x1, x2) && x < max(x1, x2) &&
                         y > min(y1, y2) && y < max(y1, y2))) {
                        anomally = true;
                        break;
                    }
                }
                if (found_x1y2 && found_x2y1 && !anomally)
                    ans = max(ans, abs(x1 - x2) * abs(y1 - y2));
            }
        }
        return ans;
    }
};