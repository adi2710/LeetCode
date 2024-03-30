class Solution:
    def sumOfPowers(self, nums: List[int], k: int) -> int:
        nums.sort();
        MOD = 10 ** 9 + 7
        
        @lru_cache(None)
        def solve(i, k, prev, pre):
            if k == 0:
                return pre
            if i == len(nums):
                return 0
            
            ans = solve(i + 1, k, prev, pre);
            if prev == -1:
                ans += solve(i + 1, k - 1, i, pre);
            if prev != -1:
                ans += solve(i + 1, k - 1, i, min(pre, nums[i] - nums[prev]))
            return ans % MOD
        
        return solve(0, k, -1, inf);