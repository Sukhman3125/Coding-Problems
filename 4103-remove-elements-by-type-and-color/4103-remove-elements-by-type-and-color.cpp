class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<tuple<int, int, int>> stck;
        int n = types.size();
        for (int i = 0; i < n; i++) {
            auto [_type, _color, _streak] = stck.empty() ? make_tuple(0, 0, 0) : stck.top();
            int streak;
            if (stck.empty() || _type != types[i] || _color != colors[i])
                streak = 1;
            else
                streak = _streak + 1;
            stck.push({types[i], colors[i], streak});
            if(streak != groupSize[types[i]])
                continue;
            for(int j=0;j<streak;j++)
                stck.pop();
        }
        return stck.empty();
    }
};