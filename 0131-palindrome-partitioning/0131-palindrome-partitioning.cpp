class Solution {
public:
    
    void findPalindromes(int i, string &s, vector<vector<bool>> &isPalindrome, vector<string> &str, vector<vector<string>> &ans)
    {
        if(i == s.size())
        {
            ans.push_back(str);
            return;
        }
        string temp;
        for(int j = i; j < s.size(); j++)
        {
            temp += s[j];
            if(isPalindrome[i][j]){
                str.push_back(temp);
                findPalindromes(j + 1, s, isPalindrome, str, ans);
                str.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool> (n, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; j++)
                isPalindrome[i - j][i + j] = 1;
            for(int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; j++)
                isPalindrome[i - j][i + j + 1] = 1;
        }
        vector<vector<string>> ans;
        vector<string> str;
        findPalindromes(0, s, isPalindrome, str, ans);
        return ans;
    }
};