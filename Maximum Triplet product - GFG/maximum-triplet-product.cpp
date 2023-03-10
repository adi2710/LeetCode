//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long ar[], int n)
    {
    	// Complete the function
    	long long mx1 = LLONG_MIN, mx2 = mx1, mx3 = mx1;
    	long long mn1 = LLONG_MAX, mn2 = mn1;
    	for(int i = 0; i < n; i++)
    	{
    	    if(mx1 < ar[i])
    	    {
    	        mx3 = mx2;
    	        mx2 = mx1;
    	        mx1 = ar[i];
    	    }
    	    else if(mx2 < ar[i])
    	    {
    	        mx3 = mx2;
    	        mx2 = ar[i];
    	    }
    	    else if(mx3 < ar[i])
    	        mx3 = ar[i];
    	    if(mn1 > ar[i])
    	    {
    	        mn2 = mn1;
    	        mn1 = ar[i];
    	    }
    	    else if(mn2 > ar[i])
    	        mn2 = ar[i];
    	}
    	return max(mx1 * mx2 * mx3, mx1 * mn1 * mn2);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends