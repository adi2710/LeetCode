func countSubarrays(v *[]int, target int) int {
    mp, sum, ans := map[int]int {0 : 1}, 0, 0
    for _, val := range *v {
        sum += val;
        val, _ := mp[sum - target]
        ans += val
        mp[sum]++
    }
    return ans
}

func numSubmatrixSumTarget(matrix [][]int, target int) int {
    n, m, ans := len(matrix), len(matrix[0]), 0
    for start := 0; start < n; start++ {
        v := make([]int, m)
        for i := start; i < n; i++ {
            for j := 0; j < m; j++ {
                v[j] += matrix[i][j]
            }
            ans += countSubarrays(&v, target)
        }
    }
    return ans
}