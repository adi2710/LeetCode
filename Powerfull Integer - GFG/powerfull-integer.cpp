//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
        // 5L 8R 9L 12L 16L 17L 17R 21R 24R 29R
        vector<pair<int, char>> range;
        for(auto x : intervals){
            range.push_back({x[0], 'L'});
            range.push_back({x[1], 'R'});
        }
        sort(range.begin(), range.end());
        int cnt = 0, ans = -1;
        for(auto x : range)
        {
            if(cnt == k)
                ans = x.first;
            if(x.second == 'L')
                cnt++;
            else
                cnt--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends