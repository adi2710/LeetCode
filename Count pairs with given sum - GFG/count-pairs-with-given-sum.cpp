//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        sort(arr, arr + n);
        int ans = 0;
        for(int l = 0, r = n - 1; l < r;)
        {
            if(arr[l] + arr[r] == k)
            {
                int cnt1 = 1, cnt2 = 1, n1 = arr[l], n2 = arr[r];
                while(l + 1 < r && arr[l + 1] == n1) l++, cnt1++;
                while(l < r - 1 && arr[r - 1] == n2) r--, cnt2++;
                if(n1 == n2){
                    int cnt = cnt1 + cnt2;
                    ans += cnt * (cnt - 1) / 2;
                }
                else
                    ans += cnt1 * cnt2;
                l++, r--;
            }
            else if(arr[l] + arr[r] < k)
                l++;
            else
                r--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
// } Driver Code Ends