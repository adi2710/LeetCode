func solve(i int, k int, arr *[]int, dp *[]int) int {
    if i == len(*arr) {
        return 0
    }
    
    if (*dp)[i] != -1 {
        return (*dp)[i]
    }
    
    mx, ans := -1, 0
    for j := i; j - i < k && j < len(*arr); j++ {
        if mx < (*arr)[j] {
            mx = (*arr)[j]
        }
        val := (j - i + 1) * mx + solve(j + 1, k, arr, dp)
        if ans < val {
            ans = val
        }
    }
    (*dp)[i] = ans
    return ans
}

func maxSumAfterPartitioning(arr []int, k int) int {
    dp := make([]int, len(arr))
    for i := range dp {
        dp[i] = -1
    }
    return solve(0, k, &arr, &dp);
}