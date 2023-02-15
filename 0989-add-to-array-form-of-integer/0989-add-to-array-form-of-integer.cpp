class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        string str = to_string(k);
        int i = num.size() - 1, j = str.size() - 1;
        k = max(i, j);
        vector<int> ans(k + 1);
        int carry = 0;
        while(i >= 0 && j >= 0)
        {
            int sum = num[i] + str[j] - '0' + carry;
            ans[k] = sum % 10;
            carry = sum / 10;
            i--, j--, k--;
        }
        while(i >= 0)
        {
            int sum = num[i] + carry;
            ans[k] = sum % 10;
            carry = sum / 10;
            i--, k--;
        }
        while(j >= 0)
        {
            int sum = str[j] - '0' + carry;
            ans[k] = sum % 10;
            carry = sum / 10;
            j--, k--;
        }
        if(carry > 0)
            ans.insert(ans.begin(), carry);
        return ans;
    }
};