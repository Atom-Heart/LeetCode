/*防御式编程思想处理边界问题*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        /*给首位各加上一个零解决边界问题*/
        vector<int> vec;
        vec.push_back(0);
        for(int num : flowerbed) vec.push_back(num);
        vec.push_back(0);
        int ans = 0;
        for(int i = 1; i < vec.size() - 1; i++){
            if(vec[i] == 0 && vec[i - 1] == 0 && vec[i + 1] == 0){
                vec[i] = 1;
                n--;
            }
            if(n <= 0) return true;
        }
        return false;
    }
};