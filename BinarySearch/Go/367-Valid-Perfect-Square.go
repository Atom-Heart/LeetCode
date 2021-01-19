import "math"

func isPerfectSquare(num int) bool {
    if num == 0{
        return false;
    }

    left, right := 1, num
    for left < right{
        mid := (left + right) >> 1;
        if mid >= num / mid{
            right = mid
        }else{
            left = mid + 1
        }
    }
    return float64(left) == math.Sqrt(float64(num))
}