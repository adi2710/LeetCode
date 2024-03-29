//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
    sort(arr, arr + size);
    int j = 0;
    for(int i = 0; i < size; i++)
    {
        j = max(j, i + 1);
        while(j < size && arr[j] - arr[i] < n) j++;
        if(j < size && arr[j] - arr[i] == n)
            return true;
    }
    return false;
}