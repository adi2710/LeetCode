//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void permute(int i, string &s, vector<string> &ans)
    {
        if(i == s.size())
            ans.push_back(s);
        unordered_set<char> st;
        for(int j = i; j < s.size(); j++)
        {
            if(st.find(s[j]) == st.end())
            {
                st.insert(s[j]);
                swap(s[i], s[j]);
                permute(i + 1, s, ans);
                swap(s[i], s[j]);
            }
        }
    }
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    permute(0, S, ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends