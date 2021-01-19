/*方法一：分治回溯*/
class Solution {
public:
    int ans = 0;
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<bool> used(10, false);
        return backTracking(n, 0, used);
    }
    int backTracking(int n, int level, vector<bool>& used){
        int count = 0;
        if(level != n){
            for(int i = 0; i < 10; i++){
                /*剪枝：当位数大于1时，首位不能为0*/
                if(i == 0 && level == 1) continue;
                if(used[i] == true) continue;
                used[i] = true;
                count += backTracking(n, level + 1, used) + 1;
                used[i] = false;
            }
        }
        return count;
    }
};

/*方法二：DP*/
/*
排列组合：n位有效数字 = 每一位都从0~9选择，且不能以0开头
一位数字： 0 ~ 9
两位数字： C10-2,第一位不能为0 -> 9*9
三位数字： C10-3,第一位不能为0: 9*9*8
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int first = 10, second = 9 * 9;
        for(int i = 2; i <= n; i++){
            first += second;
            second *= 10 - i;
        }
        return first;
    }
};