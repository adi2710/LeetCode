class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size() ;
        int ans = 0 ; 
        for(int i = 0 ; i< n ; ++i ){
            multiset<int> st ; 
            int prev = 0 ; 
            for( int j = i ; j < n ; ++j ){
                auto it = st.lower_bound(nums[j]) ;
                if(j == i ) {} 
                else if(it == st.end() ){
                    --it ; 
                    if(nums[j] - *it > 1 )  ++prev ; 
                }
                else if(it == st.begin() ){
                    if( *it - nums[j] > 1 )  ++prev ; 
                }
                else{
                    int right = *it ; 
                    --it ; 
                    int left = *it ; 
                    if(right - left > 1 ) --prev ; 
                    if(right - nums[j] > 1 ) ++prev ; 
                    if( nums[j] - left > 1 ) ++prev ;
                }
                st.insert( nums[j] ) ;
                ans += prev ; 
            }
            
            // cout<<ans<<" ";
        }
        return ans ; 
    } 
};