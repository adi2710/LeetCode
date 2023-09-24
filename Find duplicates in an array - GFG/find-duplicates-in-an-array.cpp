//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // code here
        for(int i = 0; i < n; i++)
            arr[i]++;
        unordered_set<int> st;
        for(int i = 0; i < n; i++)
        {
            int pos = abs(arr[i]) - 1;
            if(arr[pos] < 0)
                st.insert(pos);
            else
                arr[pos] = -1 * arr[pos];
        }
        vector<int> ans(st.begin(), st.end());
        sort(ans.begin(), ans.end());
        if(ans.empty())
            ans.push_back(-1);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends