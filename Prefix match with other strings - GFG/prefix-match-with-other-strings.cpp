//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){ 
        if(k > str.size())
            return 0;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            bool fl = 1;
            if(k > arr[i].size())
                fl = 0;
            for(int pos = 0; pos < k && pos < arr[i].size(); pos++)
            {
                if(arr[i][pos] != str[pos])
                {
                    fl = 0;
                    break;
                }
            }
            if(fl)
                ans++;
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
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends