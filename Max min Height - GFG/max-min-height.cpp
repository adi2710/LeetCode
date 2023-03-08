//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    bool isPossible(long long mid, int k, int w, vector<int> &a)
    {
        int n = a.size();
        long long sum = 0;
        int count = 0;
        vector<long long> pre(n + 1);
        for(int i = 0; i < n; i++)
        {
            sum += pre[i];
            if(a[i] + sum < mid)
            {
                long long diff = mid - a[i] - sum;
                count += diff;
                sum += diff;
                pre[min(i + w, n)] = -diff;
            }
        }
        return count <= k;
    }

    long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
    {
        // code here
        long long l = *min_element(a.begin(), a.end()), r = l + k + 1;
        while(r - l > 1)
        {
            long long mid = l + (r - l) / 2;
            if(isPossible(mid, k, w, a))
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends