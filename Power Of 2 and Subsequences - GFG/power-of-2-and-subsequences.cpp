//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long long numberOfSubsequences(int N, long long A[]){
        // code here
        int ans = 1;
        const int MOD = 1e9 + 7;
        for(int i = 0; i < N; i++)
        {
            if((A[i] & (A[i] - 1)) == 0)
                ans = (1ll * ans * 2) % MOD;
        }
        return (ans - 1ll + MOD) % MOD;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        long long A[N];
        for(int i=0;i<N;++i){
            cin >> A[i];
        }
        Solution ob;
        cout << ob.numberOfSubsequences(N,A) << endl;
    }
    return 0; 
} 
// } Driver Code Ends