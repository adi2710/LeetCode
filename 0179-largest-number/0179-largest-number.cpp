class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int x:nums)
            v.push_back(to_string(x));
        sort(v.begin(),v.end(),[](string a,string b){return a+b>b+a;});
        string ans;
        for(string x:v){
            if((int)ans.size()==0 && x.front()=='0')
                continue;
            ans+=x;
        }
        if((int)ans.size()==0)
            ans="0";
        return ans;
    }
};