func minWindow(s string, t string) string {
    freq1 := make([]int, 58)
	freq2 := make([]int, 58)
	cnt1, cnt2, n := 0, 0, len(s)

	for _, ch := range t {
		freq2[ch-'A']++
		if freq2[ch-'A'] == 1 {
			cnt2++
		}
	}

    st, length := -1, int(1e6)

	for i, j := 0, 0; j < n; {
		for j < n && cnt1 < cnt2 {
			freq1[s[j]-'A']++
			if freq1[s[j]-'A'] == freq2[s[j]-'A'] {
				cnt1++
			}
			j++
		}

		if cnt1 == cnt2 && length > j-i {
			st = i
			length = j - i
		}

		for i < j && cnt1 == cnt2 {
			freq1[s[i]-'A']--
			if freq1[s[i]-'A'] < freq2[s[i]-'A'] {
				cnt1--
			}
			i++
		}

		if st != -1 && length > j-i+1 {
			st = i - 1
			length = j - i + 1
		}
	}

	if st == -1 {
		return ""
	}

	return s[st : st+length]
    
}