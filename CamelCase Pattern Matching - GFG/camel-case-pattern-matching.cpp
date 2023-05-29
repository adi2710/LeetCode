//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string> ans;
        for(string &word : Dictionary)
        {
            string camel;
            for(int i = 0; i < word.size(); i++)
            {
                if('A' <= word[i] && word[i] <= 'Z')
                    camel += word[i];
            }
            int i = 0, j = 0, fl = 1;
            while(i < Pattern.size() && j < camel.size())
            {
                if(Pattern[i] == camel[j])
                    i++, j++;
                else
                {
                    fl = 0;
                    break;
                }
            }
            if(fl && i == Pattern.size())
                ans.push_back(word);
        }
        sort(ans.begin(), ans.end());
        if(ans.empty())
            ans.push_back("-1");
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends