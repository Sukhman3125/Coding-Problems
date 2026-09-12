class StockSpanner {
    stack<pair<int,int>> stck;
public:
    int next(int price) {
        int span = 1;
        while (!stck.empty() && stck.top().first <= price) {
            span += stck.top().second;
            stck.pop();
        }
        stck.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */