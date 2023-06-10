class Solution {
public:
    
    long long sumAP(int a, int d, int no)
    {
        long long sum = (2ll * a + (no - 1) * d) * no / 2;
        return sum;
    }
    
    int maxValue(int n, int index, int maxSum) {
        int l = 1, r = maxSum + 1;
        while(r - l > 1)
        {
            int mid = l + (r - l) / 2;
            int a = mid - 1, no = min(a, index), d = -1, rem = index - no;
            long long pre = sumAP(a, d, no) + rem;
            no = min(a, n - index - 1), rem = n - index - 1 - no;
            long long suf = sumAP(a, d, no) + rem;
            if(pre + mid + suf <= maxSum)
                l = mid;
            else
                r = mid;
        }
        return l;
    }
};