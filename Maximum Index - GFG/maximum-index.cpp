//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        int ans = 0;
        vector<int> mx(n), mn(n);
        mn.front() = arr[0];
        mx.back() = arr[n-1];

        for(int i = 1; i < n; i++)
            mn[i] = min(mn[i - 1], arr[i]);
        for(int i = n - 2; i >= 0; i--)
            mx[i] = max(mx[i + 1], arr[i]);
            
        int i = 0, j = 0;
        while(i < n && j < n) {
            if(mn[i] <= mx[j]) {
                ans = max(ans,j - i);
                j++;
            }
            else
                i++;
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends