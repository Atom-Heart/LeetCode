class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        res[0] = 0;//0含位为1的个数为零
        for(int i = 1; i <= num; i++){
            if(i % 2 == 1){//如果是奇数
                res[i] = res[i - 1] + 1;
            }
            else{//如果是偶数
                res[i] = res[i / 2];
            }
        }
        return res;
    }
};

//https://leetcode-cn.com/problems/counting-bits/solution/hen-qing-xi-de-si-lu-by-duadua/