//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int minThrow(int N, int arr[]){
        // code here
        unordered_map<int, int> mp;
        for(int i = 0; i + 1 < 2 * N; i += 2)
            mp[arr[i]] = arr[i + 1];
        queue<int> q;
        vector<bool> vis(31);
        q.push(1);
        vis[1] = true;
        int ans = 0;
        while(!q.empty())
        {
            for(int i = q.size(); i >= 1; i--)
            {
                int cur = q.front();
                q.pop();
                if(cur == 30)
                    return ans;
                for(int j = cur + 1; j - cur <= 6 && j <= 30; j++)
                {
                    int pos = mp.find(j) == mp.end() ? j : mp[j];
                    if(!vis[pos])
                    {
                        vis[pos] = true;
                        q.push(pos);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[2*N];
        for(int i = 0;i < 2*N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.minThrow(N, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends