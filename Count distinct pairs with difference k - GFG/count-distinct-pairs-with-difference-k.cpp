//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalPairs(vector<int>nums, int k){
	    // Code here
	    sort(nums.begin(), nums.end());
	    int n = nums.size(), j = 0, ans = 0;
	    for(int i = 0; i < n; i++)
	    {
	        j = max(j, i + 1);
	        while(j < n && nums[j] - nums[i] < k) j++;
	        if(j < n && nums[j] - nums[i] == k)
	            ans++;
	        while(i + 1 < n && nums[i + 1] == nums[i]) i++;
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
		cin >> n >> k;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.TotalPairs(nums, k);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends