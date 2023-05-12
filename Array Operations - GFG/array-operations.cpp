//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &ar) {
        // code here
        int cnt = 0, fl = 0;
        for(int i = 1; i < n; i++)
        {
            if(ar[i] == 0)
                fl = 1;
            if(ar[i - 1] > 0 && ar[i] == 0)
                cnt++;
        }
        if(!fl)
            return -1;
        if(ar.back() != 0)
            cnt++;
        return cnt;
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
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends