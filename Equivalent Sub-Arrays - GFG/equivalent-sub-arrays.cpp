//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countDistinctSubarray(int arr[], int n)
    {
        //code here.
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            mp[arr[i]] = 1;
        int k = mp.size(), ans = 0;
        mp.clear();
        for(int i = 0, j = -1, r = 0; i < n; i++)
        {
            while(j + 1 < n && mp.size() < k)
                mp[arr[++j]]++;
            if(mp.size() == k)
            {
                if(r <= j)
                {
                    r = j;
                    while(r + 1 < n && mp.find(arr[r + 1]) != mp.end())
                        r++;
                }
                ans += r - j + 1;
            }
            mp[arr[i]]--;
            if(mp[arr[i]] == 0)
                mp.erase(arr[i]);
        }
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
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;	
		cout<<ob.countDistinctSubarray(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends