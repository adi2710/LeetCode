func isPalindrome(s *string) bool {
    for l, r := 0, len(*s) - 1; l < r; l, r = l + 1, r - 1 {
        if((*s)[l] != (*s)[r]){
            return false
        }
    }
    return true
}

func reverse(s string) string { 
    rns := []rune(s)
    for i, j := 0, len(rns) - 1; i < j; i, j = i + 1, j - 1 { 
        rns[i], rns[j] = rns[j], rns[i] 
    } 
    return string(rns) 
} 

func palindromePairs(words []string) [][]int {
    mp, n, ans := map[string]int {}, len(words), [][]int {}
    for i:= 0; i < n; i++ {
        mp[reverse(words[i])] = i
    }
    for i := 0; i < n; i++ {
        for j := 0; j <= len(words[i]); j++ {
            pre, suf := words[i][:j], words[i][j:]
            preVal, preOk := mp[pre]
            sufVal, sufOk := mp[suf]
            if len(pre) != 0 && sufOk && sufVal != i && isPalindrome(&pre) {
                ans = append(ans, []int {sufVal, i})
            }
            if preOk && preVal != i && isPalindrome(&suf) {
                ans = append(ans, []int {i, preVal})
            }
        }
    }
    return ans
}