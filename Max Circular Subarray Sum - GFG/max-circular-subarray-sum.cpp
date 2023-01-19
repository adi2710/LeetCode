//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int n){
        int max_ans = INT_MIN, min_ans = INT_MAX, sum = 0, max_sum = 0, min_sum = 0;
        for(int i = 0; i < n; i++)
        {
            max_sum = max(max_sum, 0) + arr[i];
            max_ans = max(max_ans, max_sum);
            min_sum = min(min_sum, 0) + arr[i];
            min_ans = min(min_ans, min_sum);
            sum += arr[i];
        }
        if(min_ans == sum)
            return max_ans;
        return max(max_ans, sum - min_ans);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends