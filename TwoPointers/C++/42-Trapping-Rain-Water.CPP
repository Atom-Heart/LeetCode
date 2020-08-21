
/*暴力法，看每一列能存多少水*/
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;//最终的结果
        for(int i = 1; i < height.size(); i++){//遍历从正数第二个到倒数第二个的每个格子，看每个格子上能放多少水
            int left = 0;//左边的最大高度为0
            for(int j = i - 1; j >= 0; j--){//找到当前位置左最大的那个高度
                if(height[j] > left){
                    left = height[j];
                }
            }
            int right = 0;
            for(int k = i + 1; k < height.size(); k++){
                if(height[k] > right){
                    right = height[k];
                }
            }
            int num = min(left, right);//取左边高度和右边高度的最小值，木桶原理
            if(num > height[i]){//只有当Num大于height[i]的时候才能积攒下来水，等于是平的，小于说明此时的位置很高，蓄不了水
                res  = res + (num - height[i]);
            }
        }
        return res;
    }
};


/*优化1：备忘录法*/
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        vector<int> max_left(n, 0);
        vector<int> max_right(n, 0);
        max_left[0] = height[0];//第一个所有左边最大的数就是自身
        max_right[n - 1] = height[n - 1];//最后一个右边最大的数就是自身

        for(int i = 1; i < n; i++){
            max_left[i] = max(max_left[i - 1], height[i]);
        }

        for(int i = n - 2; i >= 0; i--){
            max_right[i] = max(max_right[i + 1], height[i]);
        }

        int sum = 0;
        for(int i = 1; i < n; i++){
            int start = max_left[i];
            int end = max_right[i];
            int min_num = min(start, end);
            if(min_num > height[i]){
                sum += (min_num - height[i]);
            }
        }
        return sum;
        
    }
};

/*优化2：双指针法*/
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        int res = 0;
        int left = 0;//左边界
        int right = height.size() - 1;//右边界
        int max_left = height[0];//[0, left]的最大高度
        int max_right = height[height.size() - 1];//[right, height.size() - 1]的最大高度
        while(left <= right){//区间是[left, right]
            max_left = max(max_left, height[left]);//看当前位置的高度是不是最大的，如果是，就更新
            max_right = max(max_right, height[right]);

            if(max_right > max_left){
                res += max_left - height[left];//如果就是本身最高的话，那就存不下水
                left++;
            }
            else{
                res += max_right - height[right];
                right--;
            }
        }
        return res;
    }
};
