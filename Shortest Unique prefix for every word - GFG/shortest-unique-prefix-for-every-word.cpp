//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Trie{
public:
    
    bool isEnd;
    int cntOfWords;
    Trie* child[26];
    
    Trie()
    {
        isEnd = false;
        cntOfWords = 0;
        for(int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
    
    void insert(string &s)
    {
        Trie *cur = this;
        for(char ch : s)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                cur -> child[ch - 'a'] = new Trie();
            cur -> cntOfWords++;
            cur = cur -> child[ch - 'a'];
        }
        cur -> cntOfWords++;
        cur -> isEnd = true;
    }
    
    int findPrefix(string &s)
    {
        Trie *cur = this;
        for(int i = 0; i < s.size(); i++)
        {
            if(cur -> cntOfWords == 1)
                return i;
            cur = cur -> child[s[i] - 'a'];
        }
        return s.size();
    }
};

class Solution
{
    public:
    vector<string> findPrefixes(string arr[], int n)
    {
        //code here
        Trie *trie = new Trie();
        for(int i = 0; i < n; i++)
            trie -> insert(arr[i]);
        vector<string> ans(n);
        for(int i = 0; i < n; i++)
        {
            int pos = trie -> findPrefix(arr[i]);
            ans[i] = arr[i].substr(0, pos);
        }
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends