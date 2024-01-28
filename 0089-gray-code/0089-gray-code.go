func solve(i int, n *int, vis *[]int, tmp *[]int, ans *[]int) {
    if i == (1 << *n) {
        val := (*tmp)[len(*tmp) - 1]
        if val & (val - 1) == 0 {
            *ans = append((*ans)[:0], (*tmp)...)
        }
        return
    }
    
    if len(*ans) > 0 {
        return
    }
    
    for j := 0; j <= 15; j++ {
        num, mask := (*tmp)[len(*tmp) - 1], 1 << j
        if num & mask > 0 {
            num &= ^mask
        } else {
            num |= mask
        }
        if num < (1 << *n) && (*vis)[num] == 0 {
            (*vis)[num] = 1
            *tmp = append(*tmp, num)
            solve(i + 1, n, vis, tmp, ans)
            *tmp = (*tmp)[:len(*tmp) - 1]
            (*vis)[num] = 0
        }
    }
}

func grayCode(n int) []int {
    vis, tmp, ans := make([]int, 1 << n), []int{0}, []int{}
    vis[0] = 1
    solve(1, &n, &vis, &tmp, &ans)
    return ans
}