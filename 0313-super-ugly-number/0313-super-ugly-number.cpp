#define P pair<long long, int>
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> index(primes.size(), 0);
            vector<long long> nums;
            nums.push_back(1);      
            
            priority_queue<P, vector<P>, greater<P>> pq;    // remember pair(the ugly number, who generated this ugly)
            for (int i = 0; i < primes.size(); i++)
                pq.emplace(primes[i], i);   // initial ugly = prime  * 1
            
            while (nums.size() < n)
            {
                auto [value, id] = pq.top();    // get the smallest ugly
                pq.pop();
                
                if (value != nums.back())       // check the dupe
                    nums.push_back(value);
                
                index[id]++;                             // the prime generated this small ugly number should move forward to multiply next ugly number
                pq.emplace(nums[index[id]] * primes[id], id);         // push the new ugly number to pq to participate sorting
            }
            
            return nums.back();
        }
};