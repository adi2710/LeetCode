//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{
    void merge(int l, int mid, int r, int arr[])
    {
        int i = l, j = mid + 1, k = 0;
        vector<int> temp(r - l + 1);
        while(i <= mid && j <= r)
        {
            if(arr[i] < 0)
                temp[k++] = arr[i++];
            else if(arr[j] < 0)
                temp[k++] = arr[j++];
            else if(arr[i] >= 0)
                temp[k++] = arr[i++];
            else
                temp[k++] = arr[j++];
        }
        while(i <= mid)
            temp[k++] = arr[i++];
        while(j <= r)
            temp[k++] = arr[j++];
        for(int pos = l; pos <= r; pos++)
            arr[pos] = temp[pos - l];
    }
    
    void mergeSort(int l, int r, int arr[])
    {
        if(l == r)
            return;
        int mid = l + (r - l) / 2;
        mergeSort(l, mid, arr);
        mergeSort(mid + 1, r, arr);
        merge(l, mid, r, arr);
    }
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            mergeSort(0, n - 1, arr);
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends