func minEatingSpeed(piles []int, H int) int {
	max := 0
	for _, x := range piles {
		if max < x {
			max = x
		}
	}

	left, right := 1, max

	for left < right {
		mid := (left + right) >> 1
		cnt := helper(piles, mid)
		if cnt <= H {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}

func helper(piles []int, k int) int {
	ans := 0
	for i := 0; i < len(piles); i++ {
		ans += (piles[i] + k - 1) / k
	}
	return ans
}