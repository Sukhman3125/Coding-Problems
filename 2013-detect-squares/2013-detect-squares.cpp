class DetectSquares {
private:
    int get(int key) {
        auto it = pts.find(key);
        return it == pts.end() ? 0 : it->second;
    }
    int pack(vector<int> p){
        return (p[0]<<10) | p[1];
    }
    pair<int,int> unpack(int p){
        return {p>>10, p & ((1<<10) - 1) };
    }
    unordered_map<int,int> pts;
public:
    void add(vector<int> point) {
        pts[pack(point)]++;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1];
        int cnt = 0;
        for(auto [pt, f]:pts){
            auto [x1,y1] = unpack(pt);
            if(x1!=x) continue;
            if(y1==y) continue;
            int side = y1-y;
            int x2 = x - side;

            if (x2 >= 0) {
                cnt += f
                    * get(pack({x2, y}))
                    * get(pack({x2, y1}));
            }

            x2 = x + side;
            if (x2 <= 1000) {
                cnt += f
                    * get(pack({x2, y}))
                    * get(pack({x2, y1}));
            }
        }
        return cnt;
    }
};
