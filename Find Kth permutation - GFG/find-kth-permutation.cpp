//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    string kthPermutation(int n, int k)
    {
        // code here
        vector<int> nums(n);
        int fact = 1;
        for(int i = 1; i <= n; i++)
        {
            fact *= i;
            nums[i - 1] = i;
        }
        k--;
        string ans;
        while(!nums.empty())
        {
            fact /= nums.size();
            int pos = k / fact;
            ans += to_string(nums[pos]);
            nums.erase(nums.begin() + pos);
            k %= fact;
        }
        return ans;
    }
};
//24
//1/1=1

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends