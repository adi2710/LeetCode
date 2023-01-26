class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0; 
        k++;
        while(k--)
        {
            vector<int> temp_prices = prices;
            for(auto &flight : flights)
            {
                int u = flight[0], v = flight[1], cost = flight[2];
                if(prices[u] != INT_MAX && prices[u] + cost < temp_prices[v])
                    temp_prices[v] = prices[u] + cost;
            }
            prices = temp_prices;
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};