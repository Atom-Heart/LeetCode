# 算法部分

## 动态规划
***
### 背包问题
### 1.01背包DP
题目|知识点|
:-|:-|
|[494. 目标和](https://leetcode-cn.com/problems/target-sum/)|回溯超时，可以转化为子集背包问题

### 2.博奕型DP
|题目|知识点|
:-|:-|
|[292. Nim 游戏](https://leetcode-cn.com/problems/nim-game/)|dp[n] = !(dp[n - 1] && dp[n - 2] && dp[n - 3])，先手如果想胜利且先手足够聪明（聪明的意思就是先手如果能胜利的话，一定会选择一个能让自己胜利的取法），那么只要后手有失败的可能，那么先手就会胜利。如果不管先手取几个，剩下的情况让后手去取，后手都会胜利的话，那么先手就会输|

### 3.线性DP
|题目|知识点|
:-|:-|
|[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)|经典DP问题，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]|
|[96. 不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)|G(n) = f(1) + f(2) + ··· + f(n), f(i) = G(n - i) * G(i - 1)；这个题最主要就要明白第二个公式为什么是乘法：因为当以数字i为根节点，即f(i)，左子树G(i - 1)表示i - 1个数组成的子树，右子树G(n - i)表示另外n - i个数组成的子树，因为这两个子树是独立的，所以可以使用乘法法则|
|[97.交错字符串](https://leetcode-cn.com/problems/interleaving-string/)|可以借鉴62.不同路径的思路|
***
## 数学问题

题目|知识点|
:-|:-|
|[7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)|C++中遇到int溢出时的判断方法 —> 大7负8|
|[29. 两数相除](https://leetcode-cn.com/problems/divide-two-integers/)|需要考虑到int型越界问题|

## 回溯

### 第1部分：子集问题
 
题目|知识点|
:-|:-|
|[78. 子集](https://leetcode-cn.com/problems/subsets/)|这个题目中不会出现重复元素，且每个元素只能被选一次，这就要考虑深度和选择之间的关系，在递归调用时，传入的深度参数应该是当前深度+1
|[90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)|这个题的考点就是如何去重，首先要先排序，因为子集[1,2]和子集[2,1]其实是一样的，所以子集问题可以理解为选择一个或多个元素构成的组合有多少种|

### 第2部分：字串问题
|题目|知识点|
:-|:-|
|[131. 分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/)|这个题就是求字串，但是还要保存之前求出的字串的路径，而且每个字串必须还要是回文串|

### 第2部分：剪枝
|题目|知识点|
:-|:-|
|[93. 复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)|这个题整体思路比较好想，但代码复杂，有许多剪枝的地方需要去判断|


## 分治
|题目|知识点|
:-|:-|
|[**95. 不同的二叉搜索树 II**](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)|这道题用了分治的思想，非常非常巧妙，重点看。还可以动态规划的思想做，但我没看|
|[105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|前序遍历的第一个节点一定是二叉树的根节点，然后在中序遍历中寻找根节点的位置，可以把二叉树分为左右两个子树，并且还可以知道左右子树所含节点的个数。然后再对左右子树进行相同的操作。这就是分治的思想|
|[106. 从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|后序遍历中最后一个节点一定是二叉树的根节点，然后在中序遍历中寻找根节点的位置，可以把二叉树分为左右两个子树。整体思想和上题一样|
|[108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)|分治思想，利用区间的变换，每次都取区间的中点作为根节点|
|[109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)|分治思想，和前一道比只是将连续结构换成了链式结构，需要分割链表|
|[111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)|分治|



## 二分搜索
|题目|知识点|
:-|:-|
|[29. 两数相除](https://leetcode-cn.com/problems/divide-two-integers/)|向下取整的除法就是看被除数能够减去多少个除数，一个一个减太浪费时间，应该乘倍的取减，比方说除数是3，那么第二次减就是6，第三次减就是12，以此类推。如果当被除数小于除数，就将除数重置为3，继续上面的操作|


## 双指针
|题目|知识点|
:-|:-|
|[26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)|一个指针指向能插入的位置，另一个指针指向待插入的元素。判断一个数是不是能被插入的方法是：判断这个数是不是和前一个数相等|
|[80. 删除排序数组中的重复项 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/)|这个题和前一道题的区别在于，这道题可以允许有一个数字出现两次。这两道题不难，但写出简洁的代码是有难度的|

## DFS
|题目|知识点|
:-|:-|
|[130. 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)|DFS和BFS都能做，但是我写的BFS超时了，还没有解决。核心思想就是标记和边缘的'O'联通的所有'O'|
## BFS
|题目|知识点|
:-|:-|
|[**127. 单词接龙**](https://leetcode-cn.com/problems/word-ladder/)|考察了单向BFS(超时)和双向BFS|
|||

## Morris算法
|题目|知识点|讲解|
:-|:-|:-|
|[99. 恢复二叉搜索树](https://leetcode-cn.com/problems/recover-binary-search-tree/)|Morris遍历利用的是树的叶节点左右孩子为空（树的大量空闲指针），实现空间开销的极限缩减。|[1.Morris算法讲解](https://leetcode-cn.com/problems/recover-binary-search-tree/solution/yi-wen-zhang-wo-morrisbian-li-suan-fa-by-a-fei-8/) [2.应用](https://leetcode-cn.com/problems/recover-binary-search-tree/solution/zhong-xu-bian-li-shuang-zhi-zhen-zhao-ni-xu-dui-mo/)|

## KMP算法
|题目|知识点|讲解|
:-|:-|:-|
||||

## Manacher算法
|题目|知识点|讲解|
:-|:-|:-|
||||




# 数据结构部分


## 数组

|题目|知识点|
:-|:-|
|[54. 螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)|这个题考的是数组的螺旋迭代问题，可以设置上下左右四个限制，每遍历一个方向，就相当于把该方向的这一行或一列数据删除，如果上边界大于了下边界，那么则说明遍历完毕|
|[59. 螺旋矩阵 II](https://leetcode-cn.com/problems/spiral-matrix-ii/)|同上|
|[73. 矩阵置零](https://leetcode-cn.com/problems/set-matrix-zeroes/)|基本思想就是保存矩阵中为0元素的行和列，如果想要降低空间复杂度，要利用**哨兵**技巧，把矩阵的第一行和第一列用来标记某列和某行是否出现0|

## 位操作

|题目|知识点|
:-|:-|
|[102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)|这个题的要求就是全部访问完二叉树的一层之后再去访问下一层，可以先记录当前需要访问的这层的个数，然后只从队列中取出相应个数个节点访问|
|[107. 二叉树的层次遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)|和上一个题一样，最后利用reverse函数翻转结果|
|[231. 2的幂](https://leetcode-cn.com/problems/power-of-two/)|如果一个数是二的幂，那么这个数的二进制的第一位必为1，其余位为0。则n - 1的首位为0，其余位为1|

## 树

|题目|知识点|
:-|:-|
|[**95. 不同的二叉搜索树 II**](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)|这道题用了递归的思想，非常非常巧妙，重点看。还可以动态规划的思想做，但我没看|
|[105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|前序遍历的第一个节点一定是二叉树的根节点，然后在中序遍历中寻找根节点的位置，可以把二叉树分为左右两个子树，并且还可以知道左右子树所含节点的个数。然后再对左右子树进行相同的操作。这就是分治的思想|
|[106. 从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|后序遍历中最后一个节点一定是二叉树的根节点，然后在中序遍历中寻找根节点的位置，可以把二叉树分为左右两个子树。整体思想和上题一样|
|[108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)|分治思想，利用区间的变换，每次都取区间的中点作为根节点|
|[109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)|分治思想，和前一道比只是将连续结构换成了链式结构，需要分割链表|
|[111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)|分治|
|[**116. 填充每个节点的下一个右侧节点指针**](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)|这个题可以转化成如何成对访问完美二叉树的两两相邻节点。空间复杂度为O(1)的迭代和递归做法都非常巧妙 |
|[**117. 填充每个节点的下一个右侧节点指针 II**](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/)|这题非常有意思|
|[235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)|这个题要利用二叉排序树本身的性质，如果当前节点的大小位于两个目标节点之间，那么这个节点就是最近的公共节点，如果两个节点都比当前节点大，那么LCA一定在当前节点的右子树；如果两个节点都比当前节点小，那么LCA一定在当前节点的左子树|


## 字符串

|题目|知识点|
:-|:-|
|[557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)|考察了有关于reverse和vector的迭代器的使用|


## 哈希表
|题目|知识点|
:-|:-|
|[36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)|board中的整数被限制在0~9中，因此可以分别建立哈希表来存储任意一个数在响应维度上是否出现过。这道题的主要难点在于如何判断board[i][j]是否在其属于的哪个3×3的表中出现过。9×9的矩阵可以理解为9个3×3的矩阵，要做的就是通过i,j确定board[i][j]在哪一个3×3的矩阵里，公式就是j / 3 + (i / 3) * 3|


## 链表
|题目|知识点|
:-|:-|
|[83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)|递归写法非常巧妙|
|[82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)|有迭代和递归两种写法，都比较巧妙，和上一个题思想类似|


