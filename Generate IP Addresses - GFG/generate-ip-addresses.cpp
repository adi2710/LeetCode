//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
public:
    
    void solve(int i, int lvl, string ip, string &s, vector<string> &ans)
    {
    	if (i == s.size() && lvl == 4)
    	{
    		ans.push_back(ip);
    		ans.back().pop_back();
    		return;
    	}
    	for (int j = 1; j <= 3 && i + j <= s.size(); j++)
    	{
    		string st = s.substr(i, j);
    		if ((s[i] == '0' && st.size() > 1) || stoi(st) > 255)
    			return;
    		solve(i + j, lvl + 1, ip + st + ".", s, ans);
    	}
    }
    
    vector<string> genIp(string &s) {
    	// Your code here
    	vector<string> ans;
    	solve(0, 0, "", s, ans);
    	if (ans.empty())
    		ans.push_back("-1");
    	return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends