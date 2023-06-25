class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int i, int fuel, int &finish, vector<int> &locations, vector<vector<int>> &dp)
    {
        if(dp[i][fuel] != -1)
            return dp[i][fuel];
        int ans = i == finish ? 1 : 0;
        for(int j = 0; j < locations.size(); j++)
        {
            if(i == j)
                continue;
            if(fuel >= abs(locations[i] - locations[j]))
                ans = (1ll * ans + solve(j, fuel - abs(locations[i] - locations[j]), finish, locations, dp)) % MOD;
        }
        return dp[i][fuel] = ans;
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        vector<vector<int>> dp(locations.size(), vector<int> (fuel + 1, -1));
        return solve(start, fuel, finish, locations, dp);
    }
};
