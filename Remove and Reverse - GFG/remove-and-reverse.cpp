//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string& S) {
        // code here
        int l = 0, r = S.size() - 1;
        unordered_map<char, int> mp;
        for(char ch : S)
            mp[ch]++;
        bool dir = 0;
        while(l <= r)
        {
            if(dir == 0)
            {
                while(l <= r && mp[S[l]] == 1) l++;
                if(l <= r){
                    mp[S[l]]--;
                    S[l] = '.';
                    l++;
                    dir = 1;
                }
            }
            else
            {
                while(l <= r && mp[S[r]] == 1) r--;
                if(l <= r){
                    mp[S[r]]--;
                    S[r] = '.';
                    r--;
                    dir = 0;
                }
            }
        }
        string ans;
        for(char ch : S)
        {
            if(ch != '.')
                ans += ch;
        }
        if(dir == 1)
            reverse(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends