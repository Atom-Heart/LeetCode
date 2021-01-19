func shipWithinDays(weights []int, D int) int {
	left, right := 1, 0
	for i := 0; i < len(weights); i++ {
		right += weights[i]
	}

	for left < right {
		mid := (left + right) >> 1
		if helper(weights, D, mid) {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func helper(weights []int, D int, cap int) bool {
	i := 0
	cur := 0
	days := 0

	for i < len(weights) {
		for i < len(weights) && cur+weights[i] <= cap {
			cur += weights[i]
			i++
		}

		if cur == 0 {
			return false
		} else {
			days++
			cur = 0
		}
	}

	if days <= D {
		return true
	} else {
		return false
	}
}