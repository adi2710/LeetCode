//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        int n = s.size();
        vector<int> dp(n + 1);
        for(int i = 1; i <= n; i++)
        {
            vector<int> new_dp(n + 1);
            for(int j = 1; j <= n; j++)
            {
                if(s[i - 1] == s[n - j])
                    new_dp[j] = 1 + dp[j - 1];
                else
                    new_dp[j] = max(new_dp[j - 1], dp[j]);
            }
            dp = new_dp;
        }
        return n - dp[n];
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends