//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]]++;
        int cnt = INT_MAX, ans = -1;
        for(auto x : mp)
        {
            if(x.second < cnt)
                cnt = x.second, ans = x.first;
            else if(x.second == cnt)
                ans = max(ans, x.first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends