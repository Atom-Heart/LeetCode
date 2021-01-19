import "fmt"

func maxEnvelopes(envelopes [][]int) int {
	n := len(envelopes)
	if n < 1 {
		return 0
	}

	sort.Slice(envelopes, func(a, b int) bool {
		return envelopes[a][0] < envelopes[b][0] || (envelopes[a][0] == envelopes[b][0] && envelopes[a][1] < envelopes[b][1])
	})

	dp := make([]int, n)
	for i := 0; i < n; i++ {
		dp[i] = 1
	}
	ans := 1

	for i := 1; i < n; i++ {
		for j := 0; j < i; j++ {
			if envelopes[j][1] < envelopes[i][1] && envelopes[j][0] < envelopes[i][0] {
				dp[i] = max(dp[i], dp[j]+1)
			}
		}
		ans = max(ans, dp[i])
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}