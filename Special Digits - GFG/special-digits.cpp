//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:

    const int MOD = 1e9 + 7;
    
    int power(int a, int b)
    {
        int res = 1;
        while(b)
        {
            if(b & 1)
                res = (1ll * res * a) % MOD;
            a = (1ll * a * a) % MOD;
            b >>= 1;
        }
        return res;
    }
    
    void precompute(vector<int> &fact)
    {
        fact[0] = 1;
        for(int i = 1; i < fact.size(); i++)
            fact[i] = (1ll * fact[i - 1] * i) % MOD;
    }
    
    bool containsDig(int sum, int C, int D)
    {
        while(sum)
        {
            int dig = sum % 10;
            if(dig == C || dig == D)
                return true;
            sum /= 10;
        }
        return false;
    }
    
    int bestNumbers(int N, int A, int B, int C, int D) {
        // code here
        int ans = 0;
        vector<int> fact(N + 1);
        precompute(fact);
        if(A == B)
        {
            int sum = A * N;
            if(containsDig(sum, C, D))
                ans = 1;
            return ans;
        }
        for(int i = 0; i <= N; i++)
        {
            int sum = A * i + B * (N - i);
            if(containsDig(sum, C, D))
            {
                int den = (1ll * fact[i] * fact[N - i]) % MOD;
                int res = (1ll * fact[N] * power(den, MOD - 2)) % MOD;
                ans = (ans + res) % MOD;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int A;
        scanf("%d",&A);
        
        
        int B;
        scanf("%d",&B);
        
        
        int C;
        scanf("%d",&C);
        
        
        int D;
        scanf("%d",&D);
        
        Solution obj;
        int res = obj.bestNumbers(N, A, B, C, D);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends