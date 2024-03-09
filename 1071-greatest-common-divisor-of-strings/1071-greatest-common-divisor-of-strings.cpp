class Solution {
public:
    bool check(string &str, string &ans, int hcf) {
        for(int i = 0; i < str.size(); i++) {
            if(str[i] != ans[i % hcf])
                return false;
        }
        return true;
    }
    string gcdOfStrings(string &str1, string &str2) {
        int hcf = __gcd(str1.size(), str2.size());
        if(check(str1, str1, hcf) && check(str2, str1, hcf))
            return str1.substr(0, hcf);
        return "";
    }
};