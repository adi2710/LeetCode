class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        string ans(max(i, j) + 1, '0');
        while(i >= 0 && j >= 0)
        {
            int sum = a[i] - '0' +  b[j] - '0' + carry;
            ans[max(i, j)] =  '0' + sum % 2;
            carry = sum / 2;
            i--, j--;
        }
        while(i >= 0){
            int sum = a[i] - '0' + carry;
            ans[i] =  '0' + sum % 2;
            carry = sum / 2;
            i--;
        }
        while(j >= 0){
            int sum = b[j] - '0' + carry;
            ans[j] =  '0' + sum % 2;
            carry = sum / 2;
            j--;
        }
        if(carry > 0)
            ans.insert(ans.begin(), '1');
        return ans;
    }
};