class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx;
    StockSpanner() {
        idx = -1;
        st.push({-1, INT_MAX});
    }
    
    int next(int price) {
        idx++;
        while(st.size() > 1 && st.top().second <= price)
            st.pop();
        int ans = idx - st.top().first;
        st.push({idx, price});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */