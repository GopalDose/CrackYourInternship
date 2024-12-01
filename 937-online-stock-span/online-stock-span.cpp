class StockSpanner {
public:
stack<pair<int, int>> vc;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int  span = 1;

        while(!vc.empty() && vc.top().first <= price){
            span += vc.top().second;
            vc.pop();
        }
        vc.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */