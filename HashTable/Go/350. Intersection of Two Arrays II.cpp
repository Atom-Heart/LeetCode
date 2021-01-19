func intersect(nums1 []int, nums2 []int) []int {
    hash := map[int]int{}
    res := []int{}
    for _, num1 := range nums1{
        if hash[num1] > 0{
            hash[num1]++
        }else{
            hash[num1] = 1
        }
    }

    for _, num2 := range nums2 {
        if hash[num2] > 0{
            res = append(res, num2)
            hash[num2]--
        }
    }
    return res
}