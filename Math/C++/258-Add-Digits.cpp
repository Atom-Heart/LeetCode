/*方法一：递归*/
class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        int next = 0;
        while(num){
            next += num % 10;
            num /= 10;
        }
        return addDigits(next);
    }
};
/*方法二：数学法*/
class Solution {
public:
    int addDigits(int num) {
        if(num == 0) return 0;
        else if(num % 9 == 0) return 9;
        else return num % 9;
    }
};