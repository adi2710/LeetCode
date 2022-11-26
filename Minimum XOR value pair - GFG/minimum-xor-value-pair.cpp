//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Trie{
public:
    vector<Trie*> child;
    Trie()
    {
        child.resize(2, nullptr);
    }
    
    void insert(int num)
    {
        Trie *cur = this;
        for(int i = 31; i >= 0; i--)
        {
            int isSet = (num & (1 << i)) > 0;
            if(cur -> child[isSet] == nullptr)
                cur -> child[isSet] = new Trie();
            cur = cur -> child[isSet];
        }
    }
    
    int minXor(int num)
    {
        Trie *cur = this;
        int sum = 0;
        for(int i = 31; i >= 0; i--)
        {
            int isSet = (num & (1 << i)) > 0;
            if(cur -> child[isSet] != nullptr){
                cur = cur -> child[isSet];
                sum = sum << 1;
            }
            else{
                sum = (sum << 1) | 1;
                cur = cur -> child[1 - isSet];
            }
        }
        return sum;
    }
};

class Solution{   
public:
    int minxorpair(int N, int arr[]){    
        Trie *trie = new Trie();
        int ans = INT_MAX;
        trie -> insert(arr[0]);
        for(int i = 1; i < N; i++)
        {
            ans = min(ans, trie -> minXor(arr[i]));
            trie -> insert(arr[i]);
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
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.minxorpair(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends