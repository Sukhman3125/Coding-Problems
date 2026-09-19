class Solution {
public:
    vector<int> constructRectangle(int area) {
        int diff = INT_MAX,i,j,x,l;
        for(int w = 1; w <= sqrt(area); w++){
            l = area / w;
            x = l-w;
            if(diff > l-w && l*w == area){
                diff = l - w;
                i = l;
                j = w;
            }
        }
        return {i,j};
    }
};