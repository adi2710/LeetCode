//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<int> v(arr.begin(), arr.end());
        sort(v.begin(), v.end());
        vector<long long> preSum(n + 1);
        for(int i = 1; i <= n; i++)
            preSum[i] = preSum[i - 1] + v[i - 1];
        vector<long long> ans(n);
        for(int i = 0; i < n; i++)
        {
            int pos = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            ans[i] = preSum[pos];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends