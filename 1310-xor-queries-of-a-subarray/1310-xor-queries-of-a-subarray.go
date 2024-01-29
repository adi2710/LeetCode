func xorQueries(arr []int, queries [][]int) []int {
    ans, pre, xorsum := make([]int, len(queries)), make([]int, len(arr) + 1), 0
    for i, x := range arr {
        xorsum ^= x
        pre[i + 1] = xorsum
    }
    
    for i, query := range queries {
        l, r := query[0], query[1]
        ans[i] = pre[r + 1] ^ pre[l]
    }
    return ans
}