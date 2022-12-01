//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    struct Node{
        int freq;
        char ch;
        Node *left, *right;
        Node(int freq, char ch)
        {
            this -> freq = freq;
            this -> ch = ch;
            left = right = nullptr;
        }
        Node(int freq, char ch, Node *left, Node *right)
        {
            this -> freq = freq;
            this -> ch = ch;
            this -> left = left;
            this -> right = right;
        }
    };
    
	struct compare{
        bool operator()(const Node* a, const Node* b) const
        {
            return a -> freq > b -> freq;
        }
    };
    
    void preorder(Node *root, string &path, vector<string> &ans)
    {
        if(isalpha(root -> ch))
        {
            ans.push_back(path);
            return;
        }
        path.push_back('0');
        preorder(root -> left, path, ans);
        path.pop_back();
        path.push_back('1');
        preorder(root -> right, path, ans);
        path.pop_back();
    }
    
	public:
	vector<string> huffmanCodes(string S,vector<int> f,int N)
	{
	    // Code here
	    priority_queue<Node*, vector<Node*>, compare> pq;
	    for(int i = 0; i < N; i++)
	    {
	        Node *temp = new Node(f[i], S[i]);
	        pq.push(temp);
	    }
	    while(pq.size() > 1)
	    {
	        Node *lf = pq.top();
	        pq.pop();
	        Node *rt = pq.top();
	        pq.pop();
	        int freq = lf -> freq + rt -> freq;
	        Node *temp = new Node(freq, ' ', lf, rt);
	        pq.push(temp);
	    }
	    Node *root = pq.top();
	    pq.pop();
	    vector<string> ans;
	    string path;
	    preorder(root, path, ans);
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends