//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int solve(int prev, int sum, int k, vector<vector<vector<int>>> &dp)
    {
        if(k == 0)
            return sum == 0;
        if(sum == 0)
            return 0;
        if(dp[prev][sum][k] != -1)
            return dp[prev][sum][k];
        int ans = 0;
        for(int j = prev; j <= sum; j++)
            ans += solve(j, sum - j, k - 1, dp);
        return dp[prev][sum][k] = ans;
    }
    int countWaystoDivide(int N, int K) {
        // Code here
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>> (N + 1, vector<int> (K + 1, -1)));
        return solve(1, N, K, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends