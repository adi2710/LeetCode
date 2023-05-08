//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int power(int a, int b, int m)
        {
            int res = 1;
            while(b)
            {
                if(b & 1)
                    res = (1ll * res * a) % m;
                a = (1ll * a * a) % m;
                b >>= 1;
            }
            return res;
        }
        int modulo(string s,int m)
        {
            //code here
            int ans = 0, n = s.size();
            for(int i = n - 1; i >= 0; i--)
                ans = (ans + 1ll * (s[i] - '0') * power(2, n - i - 1, m)) % m;
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends