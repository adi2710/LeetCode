//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    void permute(int i, string &s, vector<string> &ans)
    {
        if(i == s.size())
        {
            ans.push_back(s);
            return;
        }
        for(int j = i; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            permute(i + 1, s, ans);
            swap(s[i], s[j]);
        }
    }
    
    vector<string> permutation(string &S)
    {
        //Your code here
        vector<string> ans;
        permute(0, S, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends