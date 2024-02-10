func countSubstrings(s string) int {
    count, n := 0, len(s)
    for i := 0; i < n; i++ {
        for j := 0; i - j >= 0 && i + j < n; j++ {
            if s[i - j] != s[i + j] {
                break
            }
            count++
        }
        for j := 0; i - j - 1 >= 0 && i + j < n; j++ {
            if s[i - j - 1] != s[i + j] {
                break
            }
            count++
        }
    }
    return count
}