# 知识点分类

## 动态规划

题目|知识点|
:-|:-|
|[494. 目标和](https://leetcode-cn.com/problems/target-sum/)|回溯超时，可以转化为子集背包问题


## 数学问题

题目|知识点|
:-|:-|
|[7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)|C++中遇到int溢出时的判断方法 —> 大7负8

## 回溯

### 第1部分：子集问题
 
题目|知识点|
:-|:-|
|[78. 子集](https://leetcode-cn.com/problems/subsets/)|这个题目中不会出现重复元素，且每个元素只能被选一次，这就要考虑深度和选择之间的关系，在递归调用时，传入的深度参数应该是当前深度+1
|[90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)|这个题的考点就是如何去重，首先要先排序，因为子集[1,2]和子集[2,1]其实是一样的，所以子集问题可以理解为选择一个或多个元素构成的组合有多少种|


## 数组

|题目|知识点|
:-|:-|
|[54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)|这个题考的是数组的螺旋迭代问题，可以设置上下左右四个限制，每遍历一个方向，就相当于把该方向的这一行或一列数据删除，如果上边界大于了下边界，那么则说明遍历完毕|
|[59. 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)|同上|

## 位操作

|题目|知识点|
:-|:-|
|[231. 2的幂](https://leetcode-cn.com/problems/power-of-two/)|如果一个数是二的幂，那么这个数的二进制的第一位必为1，其余位为0。则n - 1的首位为0，其余位为1|

## 树

|题目|知识点|
:-|:-|
|[235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)|这个题要利用二叉排序树本身的性质，如果当前节点的大小位于两个目标节点之间，那么这个节点就是最近的公共节点，如果两个节点都比当前节点大，那么LCA一定在当前节点的右子树；如果两个节点都比当前节点小，那么LCA一定在当前节点的左子树|


