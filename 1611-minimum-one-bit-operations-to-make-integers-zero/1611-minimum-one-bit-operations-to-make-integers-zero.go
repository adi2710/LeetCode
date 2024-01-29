func minimumOneBitOperations(n int) int {
    ans := 0
    for n > 0 {
        ans ^= n
        n >>= 1
    }
    return ans
}