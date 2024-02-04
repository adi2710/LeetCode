func subarraySum(nums []int, k int) int {
    mp, sum, ans := map[int]int {0 : 1}, 0, 0
    for _, num := range nums {
        sum += num
        val, _ := mp[sum - k]
        ans += val
        mp[sum]++
    }
    return ans
}