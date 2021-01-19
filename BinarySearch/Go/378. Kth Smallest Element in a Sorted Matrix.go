func kthSmallest(matrix [][]int, k int) int {
	m, n := len(matrix), len(matrix[0])
	left, right := matrix[0][0], matrix[m-1][n-1]

	for left < right {
		mid := (left + right) >> 1
		cnt := count(matrix, mid)
		if cnt >= k {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func count(matrix [][]int, num int) int {
	cnt := 0
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[i]); j++ {
			if matrix[i][j] <= num {
				cnt++
				continue
			}
			break
		}
	}
	return cnt
}