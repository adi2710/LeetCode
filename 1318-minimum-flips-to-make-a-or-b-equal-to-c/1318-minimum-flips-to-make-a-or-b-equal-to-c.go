func minFlips(a int, b int, c int) int {
    ans := 0
    for i := 0; i < 31; i++ {
        mask := 1 << i
        if c & mask > 0 {
            if (a & mask) | (b & mask) == 0 {
                ans++
            }
        } else if c & mask == 0 {
            if a & mask > 0 {
                ans++
            }
            if b & mask > 0 {
                ans++
            }
        }
    }
    return ans
}