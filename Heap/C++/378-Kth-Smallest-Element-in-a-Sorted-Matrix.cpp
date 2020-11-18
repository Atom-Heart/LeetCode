/*方法一：大顶堆*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, less<int>> pq;
        int n = matrix.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(pq.size() == k){
                    if(matrix[i][j] < pq.top()){
                        pq.push(matrix[i][j]);
                        pq.pop();
                    }
                }
                else{
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};

/*
我的想法：创建一个大小为k的最大堆，然后依次遍历整个矩阵的元素，如果堆的大小小于k，那就直接加入元素。否则，看该元素是不是小于堆顶元素，如果小于，那就将该堆顶元素弹出，并将该元素加入堆中。但是这个做法肯定有问题，因为没有利用矩阵“每行每列元素按升序排序这个性质。矩阵的左上角是最小值，右下角是最大值”
*/

/*方法二：二分搜索的题分两种，一种是索引二分（在有序数组中的二分查找），一种是值域二分（可行解在一个区间内查找，判断这个解是否成立）。这道题就是经典的值域二分可以解决的问题，首先数组的最小值是左上角的matrix[0][0]，最大值是右下角的matrix[n - 1][n - 1]，那么第K小的值一定在这个区间中*/
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        while(left < right){
            int mid = (left + right) >> 1;
            int count = search(matrix, mid);
            if(count < k){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return left;
    }

    int search(vector<vector<int>>& matrix, int num){
        int count = 0;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] <= num){
                    count++;
                    continue;
                }
                break;//如果遇到某个数比target大，那就不用继续遍历了
            }
        }
        return count;
    }

};

