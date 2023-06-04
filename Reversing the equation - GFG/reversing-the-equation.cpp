//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    string reverseEqn (string s)
    {
        vector<string> nums;
        vector<char> operators;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            string num;
            while(i < n && ('0' <= s[i] && s[i] <= '9'))
                num += s[i++];
            nums.push_back(num);
            if(i < n)
                operators.push_back(s[i]);
        }
        string ans;
        while(!nums.empty() || !operators.empty())
        {
            ans += nums.back();
            nums.pop_back();
            if(!operators.empty()){
                ans += operators.back();
                operators.pop_back();
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends