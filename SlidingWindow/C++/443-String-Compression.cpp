/*滑动窗口：这道题实际上需要修改输入数组，只不过是原地的，这是老套路了*/
/*这道题的启发就是：
1.不一定非要去维护窗口里面的元素，可以在扩张窗口的时候什么也不做，只去修改右边界，因为也没什么可做的
2.这里把有边界放到了chars.size()，因为需要在右边界完成扩张的时候去收缩左边界，依次检查窗口里的元素
3.cnt相当于待插入位置，就是之前学的循环不变量
*/
class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int left = 0, right = 0, cnt = 0;
        for(;right <= chars.size(); right++){
            if(right == chars.size() || chars[right] != chars[left]){
                chars[cnt] = chars[left];
                cnt++;
                int len = right - left;
                if(len > 1){//长度为1的话不用添加1到压缩数组中
                    string str = to_string(len);
                    for(int i = 0; i < str.size(); i++){
                        chars[cnt++] = str[i];
                    }
                }
                left = right;
            }
        }
        return cnt;
    }
};