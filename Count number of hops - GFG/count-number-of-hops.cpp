//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        if(n <= 2)
            return n;
            
        long long a = 1, b = 1, c = 2, ans = 0;
        const int MOD = 1e9 + 7;
        
        for(int i = 3; i <= n; i++)
        {
            ans = (a + b + c) % MOD;
            a = b;
            b = c;
            c = ans;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends