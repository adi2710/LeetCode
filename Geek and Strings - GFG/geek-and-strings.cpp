//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Trie{
public:
    
    bool isEnd;
    int cntOfWords;
    vector<Trie*> child;
    
    Trie()
    {
        isEnd = false;
        cntOfWords = 0;
        child.resize(26, nullptr);
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
        for(char ch : s)
        {
            if(cur -> child[ch - 'a'] == nullptr)
                return 0;
            cur = cur -> child[ch - 'a'];
        }
        return cur -> cntOfWords;
    }
};

class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        Trie *trie = new Trie();
        for(int i = 0; i < N; i++)
            trie -> insert(li[i]);
        vector<int> ans;
        for(int i = 0; i < Q; i++)
            ans.push_back(trie -> findPrefix(query[i]));
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends