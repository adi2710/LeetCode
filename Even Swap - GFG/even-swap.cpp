//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            // Code here
            int prev = (a[0] & 1), j = 0;
            for(int i = 0; i < a.size(); i++)
            {
                if((a[i] & 1) ^ prev)
                {
                    sort(a.begin() + j, a.begin() + i, greater<int>());
                    j = i;
                    prev = (a[i] & 1);
                }
            }
            sort(a.begin() + j, a.end(), greater<int>());
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends