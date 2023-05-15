//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    long long countBits(long long N) {
        // code here
        long long ans = 0;
        N++;
        for(long long i = 2; i <= 1e9; i *= 2)
        {
            long long cnt = N  / i;
            ans += cnt * (i / 2);
            long long rem = N % i;
            ans += max(0ll, rem - (i / 2));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        long long N;
        scanf("%lld",&N);
        
        Solution obj;
        long long res = obj.countBits(N);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends