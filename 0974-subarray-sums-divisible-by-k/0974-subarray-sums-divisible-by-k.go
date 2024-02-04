func subarraysDivByK(nums []int, k int) int {
    mp, sum, ans := map[int]int {0 : 1}, 0, 0
    for _, num := range nums {
        sum = ((sum + num) % k + k) % k
        val, _ := mp[sum]
        ans += val
        mp[sum]++
    }
    return ans
}