# 算法部分

## 动态规划
***
### 1.背包DP
### 1.1 01背包
题目|知识点|
:-|:-|
|[416. 分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)|判断`true`or`false`的01背包|
|[474. 一和零](https://leetcode-cn.com/problems/ones-and-zeroes/)|选择求和问题，可以转化成01背包，考察01背包滚动数组优化，**从大到小遍历**|
|:one::star:[494. 目标和](https://leetcode-cn.com/problems/target-sum/)|回溯超时，可以转化为01背包,**背包的体积可能为负数，需要引入一个偏移量将负数变为正数**|
### 1.2 完全背包
题目|知识点|
:-|:-|
|[322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)|求最值的完全背包|
|:one:[518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)|**完全背包+记数DP**，在写二维和三维的时候一定要注意**当前背包容量j的范围是从1开始**，从0开始会有bug，因为在`j = 0`的状态多加了|
|:one::star:[377. 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)|只是看着像完全背包，完全背包不统计顺序不同的序列。`dp[i]`表示target为`i`的组合个数,所以`dp[i] = dp[i - num1] + dp[i - num2] + .....`|
|[638. 大礼包](https://leetcode-cn.com/problems/shopping-offers/)||
### 1.3 多重背包
题目|知识点|
:-|:-|
### 1.4 分组背包
题目|知识点|
:-|:-|


### 2.博奕型DP
|题目|知识点|
:-|:-|
|[292. Nim 游戏](https://leetcode-cn.com/problems/nim-game/)|dp[n] = !(dp[n - 1] && dp[n - 2] && dp[n - 3])，先手如果想胜利且先手足够聪明（聪明的意思就是先手如果能胜利的话，一定会选择一个能让自己胜利的取法），那么只要后手有失败的可能，那么先手就会胜利。如果不管先手取几个，剩下的情况让后手去取，后手都会胜利的话，那么先手就会输|

### 3.线性DP
|题目|知识点|
:-|:-|
|:one::star::fire:[44. 通配符匹配](https://leetcode-cn.com/problems/wildcard-matching/)|主要记住怎么处理`*`，用到了完全背包的优化方式|
|[62. 不同路径](https://leetcode-cn.com/problems/unique-paths/)|经典DP问题，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]|
|[72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)|`dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1])`|
|[97.交错字符串](https://leetcode-cn.com/problems/interleaving-string/)|可以借鉴62.不同路径的思路|
|[132. 分割回文串 II](https://leetcode-cn.com/problems/palindrome-partitioning-ii/)|dp[i] = min(dp[i], dp[j] + 1 for j in range(i) if s[j + 1, i]是回文);dp[i]表示字符串s[0 ~ i]分割成回文字串的个数|
|[135. 分发糖果](https://leetcode-cn.com/problems/candy/)|一知半解|
|:star:[139. 单词拆分](https://leetcode-cn.com/problems/word-break/)|状态定义不好想|
|:star:[140. 单词拆分 II](https://leetcode-cn.com/problems/word-break-ii/)|**DP+记忆化搜索+字符串区间**，状态定义有技巧，比较难想|
|:star:[174. 地下城游戏](https://leetcode-cn.com/problems/dungeon-game/)|**反向DP**，从终点向起点进行状态转移|
|[304. 二维区域和检索 - 矩阵不可变](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/)|**计算矩阵区域和**，也就是计算坐标`(i,j)`左上角的区域内的和，状态转移方程：`dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + matrix[i][j]`|
|[377. 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)|**这道题有点像背包问题，但是同样数字的不同排列属于不同答案这一点和背包问题不同**,这一题的整体思路其实和本系列其他题目差不多，但是这道题只是求路径的总数，不需要求路径本身，用回溯会超时`dp[i] += dp[i - num]`|
|[357. 计算各个位数不同的数字个数](https://leetcode-cn.com/problems/count-numbers-with-unique-digits/)|方法一：**分治回溯**，主要在于一个细节：当数字的位数大于2时，首位不能为0。方法二：数字的排列组合|
|[368. 最大整除子集](https://leetcode-cn.com/problems/largest-divisible-subset/)|有点类似于300.最长上升子序列。这道题的关键在于**需要返回的是路径而不是状态**|
|:one::star:[392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/)|**字串匹配问题,如果有大量待匹配字串，该如何提速呢？**|
|[413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/)|基本题目，考察如何选取状态和初始值。数学做法很巧妙，利用了**差分数组**|
|:fire::star:[516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)|两个元素相等：`if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;`。**两个元素不相等：**`dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])`。**要注意填表顺序**|
|[650. 只有两个键的键盘](https://leetcode-cn.com/problems/2-keys-keyboard/)|很难，不会|
|[5631. 跳跃游戏 VI](https://leetcode-cn.com/problems/jump-game-vi/)|**单调队列优化**|

### 4.记数DP
|题目|知识点|
:-|:-|
|[63. 不同路径 II](https://leetcode-cn.com/problems/unique-paths-ii/)|基础题，初始化初始状态的时候要小心一些边界调节|
|:one:[91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)|各种用例很恶心，要认真读题|

### 5.区间DP
|题目|知识点|
:-|:-|
|:two::star:[375. 猜数字大小 II](https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/)|**博弈思想+区间DP+极小化极大**，状态表示：一.集合：i~j猜数字，最坏情况得到的最低成本。2.属性：最小值。二、状态计算：`dp[i][j] = min(dp[i][j], max(dp[i][k - 1], dp[k + 1][j]) + k)`|
### 6.树型DP
|题目|知识点|
:-|:-|
|:two::fire:[96. 不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)|G(n) = f(1) + f(2) + ··· + f(n), f(i) = G(n - i) * G(i - 1)；这个题最主要就要明白第二个公式为什么是乘法：因为当以数字i为根节点，即f(i)，左子树G(i - 1)表示i - 1个数组成的子树，右子树G(n - i)表示另外n - i个数组成的子树，因为这两个子树是独立的，所以可以使用乘法法则|

### 7.股票问题
|题目|知识点|
:-|:-|
|[121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)|只能交易一次；不用枚举交易次数;`dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); dp[i][1] = max(dp[i - 1][1], -prices[i]);`|
|[122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)|能交易无限次；`dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i])`|
|[123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)|能交易两次；此时需要枚举交易次数`j`（到第`i`天为止，最多进行多少次交易），`dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i])`|
|[188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)|只能交易K次;注意`k == 0 和 i == 0`的base case，状态转移方程和123一样|
|[309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)||
|[714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)|`dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i] - fee)`|
### 8.打家劫舍问题
|题目|知识点|
:-|:-|
|[198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)|基础题，线性DP|
|[213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)||
|[337. 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/)||
### 9.最长子序列问题

> 子串与子序列区别：子串不可跳跃，子序列可以跳跃，如 “AC”是“ABCDEFG”的子序列，而不是子串。 而“ABC”则是其子串

|题目|知识点|
:-|:-|
|[128. 最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/)||
|[300. 最长上升子序列](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/)|`dp[i]`表示以`nums[i]`**结尾**的序列，不能把状态定义成“只考虑前i个数”|
|[354. 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/)|先排序，然后就可以转化为最长上升子序列问题|
|[516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)||
|[659. 分割数组为连续子序列](https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/)|**贪心**，以`nums[i]`结尾的子序列作为状态考虑问题。方法一：**哈希+堆**。方法二：**双哈希**|
|[673. 最长递增子序列的个数](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/)||
|[674. 最长连续递增序列](https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/)||
|:two::fire:[718. 最长重复子数组](https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/)|以`str[i]`结尾的字串作为状态。`if(A[i] == B[j]) dp[i][j] == dp[i - 1][j - 1] + 1`|
|[1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/)|`dp[i][j]`表示所有在第一个序列的前`i`个字母中出现，且在第二个序列前`j`个字母中出现的子序列。在计算状态的时候，可以按照选不选第`i`个或第`j`个字母为标准将状态划分为(0代表选，1代表不选)00，01，10，11。这道题的难度在于理解**状态的包含关系**：00一定是01和10的子集，所以不用单独判断；01的状态并不是`dp[i - 1][j]`，因为`dp[i - 1][j]`并不一定以`str2[j]`结尾，但是01是`dp[i - 1][j]`的子集，**这种求最值的情况可以通过求大的集合得出小集合的最值**|
|[1312. 让字符串成为回文串的最少插入次数](https://leetcode-cn.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/)||

### 10.数塔
|题目|知识点|
:-|:-|
|[64. 最小路径和](https://leetcode-cn.com/problems/minimum-path-sum/)|简单|
|[118. 杨辉三角](https://leetcode-cn.com/problems/pascals-triangle/)|简单|
|[119. 杨辉三角 II](https://leetcode-cn.com/problems/pascals-triangle-ii/)|简单|
|[120. 三角形最小路径和](https://leetcode-cn.com/problems/triangle/)|简单|
### 11.斐波那契数列
|题目|知识点|
:-|:-|
|[509. 斐波那契数](https://leetcode-cn.com/problems/fibonacci-number/)|`dp[i] = dp[i - 1] + dp[i - 2]`|
|[1137. 第 N 个泰波那契数](https://leetcode-cn.com/problems/n-th-tribonacci-number/)|同上|
|[70. 爬楼梯](https://leetcode-cn.com/problems/climbing-stairs/)|同上|
|[746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/)|题目描述很蠢
|[198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)|`dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 2])`|
|:one::star:[213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/solution/)|**将环形转化为两个线行**，一个是直接不选第一个，一个直接不选最后一个，答案就是这两个情况的最大值|

***

## 回溯

### 第1部分：子集问题
题目|知识点|
:-|:-|
|[78. 子集](https://leetcode-cn.com/problems/subsets/)|这个题目中不会出现重复元素，且每个元素只能被选一次，这就要考虑深度和选择之间的关系，在递归调用时，传入的深度参数应该是当前深度+1
|[90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)|这个题的考点就是如何去重，首先要先排序，因为子集[1,2]和子集[2,1]其实是一样的，所以子集问题可以理解为选择一个或多个元素构成的组合有多少种|
|||

### 第2部分：字串问题
|题目|知识点|
:-|:-|
|[131. 分割回文串](https://leetcode-cn.com/problems/palindrome-partitioning/)|这个题就是求字串，但是还要保存之前求出的字串的路径，而且每个字串必须还要是回文串|
|:::star:[842. 将数组拆分成斐波那契序列](https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/)|**为预防当字符串转整型出现溢出，可以在操作前判断是否溢出**。用字符串的大数加法会溢出|

### 第3部分：组合问题
|题目|知识点|
:-|:-|
|[39. 组合总和](https://leetcode-cn.com/problems/combination-sum/)|**无重复数字，但每个数字可以重复使用**。需要通过剪枝去除不必要的计算，**通过排序数组，传入回溯的起始位置来去重**|
|[40. 组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/)|**有重复数字，但每个数字只能用一次**,利用了set去重|
|[216. 组合总和 III](https://leetcode-cn.com/problems/combination-sum-iii/)|大同小异|

### 第4部分：排列问题
|题目|知识点|
:-|:-|
|[47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/)|每个数字只能用一次，但是有重复数字。需要考虑**去重**。剪枝的条件是`if(i - 1 >= 0 && nums[i] == nums[i - 1] && used[i - 1] == false)`|


### 第5部分：剪枝
|题目|知识点|
:-|:-|
|[93. 复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)|这个题整体思路比较好想，但代码复杂，有许多剪枝的地方需要去判断|
|[39. 组合总和](https://leetcode-cn.com/problems/combination-sum/)|**无重复数字，但每个数字可以重复使用**。需要通过剪枝去除不必要的计算，**通过排序数组，传入回溯的起始位置来去重**|
|[40. 组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/)|**有重复数字，但每个数字只能用一次**,利用了set去重|
|[216. 组合总和 III](https://leetcode-cn.com/problems/combination-sum-iii/)|大同小异|
### 第6部分：其他
|题目|知识点|
:-|:-|
|:one::fire:[17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)|经典dfs|
|:one::fire:[22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)|**1.任意前缀中，`(` 个数大于等于`)`个数。2.左右括号数量相等**|
|[51. N 皇后](https://leetcode-cn.com/problems/n-queens/)|精髓在于如何判断当前棋盘有效：先行后列依次放queen，**只需判断当前放置的queen左上和右上斜线和当前列是否存在queen就可以了**|




## 贪心

> 1.如果题目中出现让什么数字最大最小，字符串字典序最大之类的题目，使用单调栈
> 2.经常使用大小堆获取迭代过程中的最值

|题目|知识点|
:-|:-|
|[45. 跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)|和55思路基本一样|
|[55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/)|定一个最大值，然后用`nums[i] + i`不断去更新最大值，如果最大值小于等于`i`，说明无法到达终点|
|:one::star:[134. 加油站](https://leetcode-cn.com/problems/gas-station/)|如果从第`i`个点无法走到第`j`个点，那么说明`[i + 1, j - 1]`中的所有点都走不到第`j`个点|
|:one::fire::star:[135. 分发糖果](https://leetcode-cn.com/problems/candy/)|**贪心+记忆化搜索**；问题可以转化为从`ratings[i]`为中心，能向左右走的**最大步数**，因为分数可以理解为台阶，从高台阶可以走到低台阶。|
|[334. 递增的三元子序列](https://leetcode-cn.com/problems/increasing-triplet-subsequence/)|双指针贪心，非常巧妙，并不需要求出递增三元子序列，只需要去判断|
|:one:[376. 摆动序列](https://leetcode-cn.com/problems/wiggle-subsequence/)|先**去除vector中的重复元素**选择极大或极小值|
|:fire:[402. 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/)|有一些边界条件需要注意，比如说去除前导零|
|:star:[435. 无重叠区间](https://leetcode-cn.com/problems/non-overlapping-intervals/)|**区间调度问题**，可以从正反两个方面去考虑。正面：将**区间按左边界升序排序**，如果两个区间出现重叠，那就选择右区间小的那个区间。反向思考：**[求出最多不重复的区间](https://leetcode-cn.com/problems/non-overlapping-intervals/solution/tan-xin-suan-fa-zhi-qu-jian-diao-du-wen-ti-by-labu/)**，这是将区间按照右边界升序排序的|
|:two::star:[659. 分割数组为连续子序列](https://leetcode-cn.com/problems/split-array-into-consecutive-subsequences/)|**贪心+大小堆**，如果存在一个以`nums[i] - 1`为结尾的子序列，那么`nums[i]`就可以和其组成长度加一的新的子序列；如果有多个长度以`nums[i] - 1`结尾的子序列，那么就选择一个长度最小的，所以需要使用最小堆|
|:one::star:[860. 柠檬水找零](https://leetcode-cn.com/problems/lemonade-change/)|贪心性质隐藏的很好，在给20找零的时候，优先使用一张10和一张5的，其次选择三张5的|
|:one::star:[1642. 可以到达的最远建筑](https://leetcode-cn.com/problems/furthest-building-you-can-reach/)|精髓的地方在于去维护一个大小和梯子数量一样大的**最小堆**，用来存储到目前为止最大的n个楼间距|
|[1647. 字符频次唯一的最小删除次数](https://leetcode-cn.com/problems/minimum-deletions-to-make-character-frequencies-unique/)|第一次做的时候思考不出解决策略，不知道怎么做会使删除次数最小，因为删除当前数字会影响到其他数字，没有想到先**从大到小排序，先从大的开始删，使删除当前频率只会影响后面的而不会影响前面的**|
|:one:[1663. 具有给定数值的最小字符串](https://leetcode-cn.com/problems/smallest-string-with-a-given-numeric-value/)|差不多能想到贪心，但是还是用dfs做了，很呆。能选1就选1，选不了就让后面位置都选最大的，当前选一个尽可能小的|



## 分治
|题目|知识点|
:-|:-|
|[**95. 不同的二叉搜索树 II**](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)|这道题用了分治的思想，非常非常巧妙，重点看。还可以动态规划的思想做，但我没看|
|[105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|前序遍历的第一个节点一定是二叉树的根节点，然后在中序遍历中寻找根节点的位置，可以把二叉树分为左右两个子树，并且还可以知道左右子树所含节点的个数。然后再对左右子树进行相同的操作。这就是分治的思想|
|[106. 从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|后序遍历中最后一个节点一定是二叉树的根节点，然后在中序遍历中寻找根节点的位置，可以把二叉树分为左右两个子树。整体思想和上题一样|
|[108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)|分治思想，利用区间的变换，每次都取区间的中点作为根节点|
|[109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)|分治思想，和前一道比只是将连续结构换成了链式结构，需要分割链表|
|[111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)|分治|
|:star:[241. 为运算表达式设计优先级](https://leetcode-cn.com/problems/different-ways-to-add-parentheses/)|给表达式加括号，看最多能得出多少结果。利用分治的思想分别处理运算符左右的计算结果，然后两两组合|
|:star:[395. 至少有K个重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters/)|**hash+分治+双指针**，这是一道综合性很强的题 |


## 二分搜索
> 二分流程：确定二分边界；边界二分代码框架；设计一个check(性质)；判断区间如何更新；如果用模板二，计算mid时加1。总结：check函数为真的那一部分在区间右边（也就是mid右边直接不考虑了），用模板一，否则模板二
> 1.70%的用二分解决的题目都用到了单调性
> 2.95%的二分题目都是去找一个性质可以把整个区间分成两段，一半满足这个性质，一半不满足这个性质，也可以得到前一半的左端点值，也可以得到后一半的右端点

|题目|知识点|
:-|:-|
|:star:[29. 两数相除](https://leetcode-cn.com/problems/divide-two-integers/)|利用**二进制思想**，将被除数表示为1个除数 + 2个除数 + 4个除数 + 8个除数....|
|:one::star:[33. 搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)|先找旋转数组中的最小值，然后确认`target`在哪个区间中，然后再用二分搜索|
|:star:[34. 在排序数组中查找元素的第一个和最后一个位置](https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/)|**在含有重复元素的数组中搜索上下标**，二分搜索的小变种，相当于做了两次搜索，第一次搜索左边界，当`nums[mid] == target`时不能直接返回，必须要确保`mid`左边没有`target`才可以；第二次搜索右边界，返回的原则同上|
|[35. 搜索插入位置](https://leetcode-cn.com/problems/search-insert-position/)|常规题目|
|:one::fire::star:[50. Pow(x, n)](https://leetcode-cn.com/problems/powx-n/)|**快速幂思想，将幂次转换为二进制**|
|[69. Sqrt(x)](https://leetcode-cn.com/problems/sqrtx/)|找到第一个`n * n <= x`的位置，用模板二|
|[74. 搜索二维矩阵](https://leetcode-cn.com/problems/search-a-2d-matrix/)|**一维转二维**，`x = cur / n(列数)， y = cur % n`|
|:one:[81. 搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)|这道题主要要明白为什么旋转数组含有**重复**元素的时候不能用二分。考察了分析两段性正确性问题|
|:one:[153. 寻找旋转排序数组中的最小值](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/)|check条件我没想到。每次二分`nums[mid]`是确定的，就要看target在`nums[mid]`的哪一边|
|[154. 寻找旋转排序数组中的最小值 II](https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/)|和上一题思路一样，**删除重复部分保证两段性**|
|[162. 寻找峰值](https://leetcode-cn.com/problems/find-peak-element/)|二分的思想就是：**根据某种情况，直接能去掉一半元素**。这道题只是要求我们返回任意一个顶峰，所以我们只需要确定任意一半至少含有一个顶峰就行了，另外一半可以舍弃，我们只需要将`nums[mid]`和`nums[mid+1]`作比较就可以了。**这道题不是有序数组但是却可以用二分法去做**|
|:one::fire:[240. 搜索二维矩阵 II](https://leetcode-cn.com/problems/search-a-2d-matrix-ii/)|技巧题，以矩阵的**右上角**为起点，判断该点是否等于target，如果`matrix[i][j] > target`，说明`j`列以下的所有数都大于`target`,所以删除第`j`列；行同理|
|:one::star:[287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/)|利用**抽屉原理**。|
|:one::star:[378. 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)|**值域搜索**,可行解在一个区间内查找，判断这个解是否成立|
|[532. 数组中的 k-diff 数对](https://leetcode-cn.com/problems/k-diff-pairs-in-an-array/)|**sort+set去重+二分**|
|[540. 有序数组中的单一元素](https://leetcode-cn.com/problems/single-element-in-a-sorted-array/)|用位运算很好做，用二分比较难想，而且细节很多|
|:star:[875. 爱吃香蕉的珂珂](https://leetcode-cn.com/problems/koko-eating-bananas/)|难点在于**除法向上取整问题**，**(被除数 + 除数 - 1) / 除数**|
|:star:[1011. 在 D 天内送达包裹的能力](https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/)|和875思想一样，就是check函数有些细节难写|
|[5643. 将数组分成三个子数组的方案数](https://leetcode-cn.com/problems/ways-to-split-array-into-three-subarrays/)|**用二分搜左右边界**，没做出来|


## 双指针
> 1.有时候使用双指针前需要先排序
> 
|题目|知识点|
:-|:-|
|:one::fire:[11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)|脑筋急转弯，做法可以用反证法证明|
|:three::fire::star:[15. 三数之和](https://leetcode-cn.com/problems/3sum/)|**三指针+去重**|
|:two::fire::star:[18. 四数之和](https://leetcode-cn.com/problems/4sum/)|**四指针+去重**，用两个for循环表示前两个指针，在进行双指针查找，这道题的去重手法很重要，重点看|
|:star:[26. 删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)|一个指针指向能插入的位置，另一个指针指向待插入的元素。判断一个数是不是能被插入的方法是：判断这个数是不是和前一个数相等|
|:star:[56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)|如果区间重复，则将区间合并为一个区间。**经典字符串题目**|
|[80. 删除排序数组中的重复项 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/)|这个题和前一道题的区别在于，这道题可以允许有一个数字出现两次。这两道题不难，但写出简洁的代码是有难度的|
|:star:[392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/)|**字串匹配问题，思想不要被限制，我一直在想用hash做。如果有大量待匹配字串，该如何提速呢？**|
|:star:[658. 找到 K 个最接近的元素](https://leetcode-cn.com/problems/find-k-closest-elements/)|**反向思考！！**。保留K个元素，就相当于删除n - k个元素。我一开始的想法是从最接近x的数向外搜索，其实可以转化为从两边删除逼近x|

## 滑动窗口

> 1.找到一个连续范围，使其满足某个条件

|题目|知识点|
:-|:-|
|:star:[3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)|经典滑动窗口题目|
|:one::fire:[76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/solution/)|不会做的点在于不知道怎么判断窗口是否合法|
|[209. 长度最小的子数组](https://leetcode-cn.com/problems/minimum-size-subarray-sum/)|**找一个范围使其值满足条件，要联想到滑动窗口**，代码的写法符合滑动窗口的经典框架。思考什么时候增大窗口，增大了以后又怎么对数据进行修改，什么时候减小窗口，减小了以后又要对数据做什么修改，什么时候停止减小窗口|
|:star:[424. 替换后的最长重复字符](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)|这道题使用了**平移窗口**的策略，因为求的是最大长度，不需要去缩小窗口|
|:one::star:[438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/)|题目中包含一个经典技巧：**使用一个额外变量记录窗口的合法数据个数**。和76题的思想是一样的，`window`只记录需要的字符个数|
|:fire::star:[443. 压缩字符串](https://leetcode-cn.com/problems/string-compression/)|**滑动窗口+循环不变量**,扩张窗口的时候可以什么都不做，如果不满足收缩窗口的条件，只移动right坐标就行。思路要灵活，不一定一定要有一个数据结构维护窗口内的元素|
|:star:[1658. 将 x 减到 0 的最小操作数](https://leetcode-cn.com/problems/minimum-operations-to-reduce-x-to-zero/)|逆向思考，可以转化为滑动窗口问题|
|[面试题 01.06. 字符串压缩](https://leetcode-cn.com/problems/compress-string-lcci/)|和**443**基本一样，但没有用循环不变量，稍简一点|
## DFS
|题目|知识点|
:-|:-|
|[79. 单词搜索](https://leetcode-cn.com/problems/word-search/)|利用DFS向四个方向去搜索，同时记录已经访问过的节点，设置搜索深度用来标识是否完成搜索|
|[130. 被围绕的区域](https://leetcode-cn.com/problems/surrounded-regions/)|DFS和BFS都能做，但是我写的BFS超时了，还没有解决。核心思想就是标记和边缘的'O'联通的所有'O'|
|[329. 矩阵中的最长递增路径](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/)|**DFS+记忆化**|
|[386. 字典序排数](https://leetcode-cn.com/problems/lexicographical-numbers/)|先序DFS，以1-9为根节点，DFS中每次能选择0-9，相当于十叉树的先序遍历|
|:star:[417. 太平洋大西洋水流问题](https://leetcode-cn.com/problems/pacific-atlantic-water-flow/)|**反向DFS**，从目标点向起点反向搜索 |
## BFS

> 1.多源BFS求最短或最长路径：求最短路径，只要找到目标值就返回。最长路径：所有目标值都看完以后再返回。

|题目|知识点|
:-|:-|
|:star:[**127. 单词接龙**](https://leetcode-cn.com/problems/word-ladder/)|考察了单向BFS(超时)和**双向BFS**|
|:fire::star:[542. 01 矩阵](https://leetcode-cn.com/problems/01-matrix/)|**最短路径+多源BFS+反向思考**|
|[695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)|经典BFS|
|:fire::star:[1162. 地图分析](https://leetcode-cn.com/problems/as-far-from-land-as-possible/)|方法一：和542一样，每个结点都记录扩散到次数需要的距离。方法二：**层次BFS计算步数**，看看一共需要扩散多少步能扩散整个矩阵|
|[剑指 Offer 13. 机器人的运动范围](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)|常规BFS|

## 数学
|题目|知识点|
:-|:-|
|[7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)|C++中遇到int溢出时的判断方法 —> 大7负8：**乘除法防止溢出**|
|[29. 两数相除](https://leetcode-cn.com/problems/divide-two-integers/)|**有正负的非超大数除法**，思考被**被除数能减去多少个除数**，需要考虑到int型越界问题|
|[43. 字符串相乘](https://leetcode-cn.com/problems/multiply-strings/)|**用双指针模拟竖式乘法**，从个位开始，依次与另外一个操作数的每一位依次相乘，然后将得到的结果累加。`num1[i]`和`num2[j]`乘积对应的就是`res[i+j]`和`res[i+j+1]`|
|[69. x 的平方根](https://leetcode-cn.com/problems/sqrtx/)|**一个数的平方根大于0小于等于其一半的平方**，这个题要考虑很多细节，比如是数字0，数字1，或者一个很大的数。利用二分搜索的时候要取**右中间值**|
|[169. 求众数I](https://leetcode-cn.com/problems/majority-element/)|找到一个数字的出现个数是大于n/2的，利用**摩尔投票法**，数字相同就将计数值加1，不相同就减1，如果减到零就换人，最后剩下的那个元素就是答案|
|:star:[172. 阶乘后的零](https://leetcode-cn.com/problems/factorial-trailing-zeroes/)|这道题绝不能真的把阶乘算出来。**两个数组相乘末尾产生零一定是因为两个数有因子2和5**，所以问题可以转化为计算`n!`最多可以分解出多少2和5？有因为2比5多，所有问题又能转化为`n!`最多能分解出多少5|
|[202. 快乐数](https://leetcode-cn.com/problems/happy-number/)|一个数可以转化为其每一位的数的平方之和，判断最终能不能转化为1.类似与求环问题，可以往双指针上去思考|
|[**204. 计数质数**](https://leetcode-cn.com/problems/count-primes/)|判断素数的时候可以优化，只需要在[2, sqrt(n)]范围内看能不能被整除就可以了。更优化的算法是空间换时间，当一个数是素数时，这个数的倍数都不是素数。在这个基础上还能优化|
|[229. 求众数 II](https://leetcode-cn.com/problems/majority-element-ii/)|**如果要选出现个数超过n/m(2,3,4,5,6)的元素，那么最多有m - 1个答案**。这道题让求大于n/3的答案，所以最多有两个数。同样利用**摩尔投票法**，创建两个候选人，然后遍历整个数组去配对，然后检查候选人的票数是否大于n/3|
|[258. 各位相加](https://leetcode-cn.com/problems/add-digits/)|引入了数根的概念，了解一下数根的作用和计算|
|[263. 丑数](https://leetcode-cn.com/problems/ugly-number/)|了解什么是丑数|
|:star:[264. 丑数 II](https://leetcode-cn.com/problems/ugly-number-ii/)|这道题要充分利用丑数的自身性质，有点类似于求质数那道题的思想：利用已经有的质数去生成新的质数。方法一：大小堆优化筛法。方法二：**归并排序**+DP，所谓归并，由于因子有2，3，5，所有丑数可以表示成小的丑数×2、×3、×5，每次都选择最小的那个数字，然后移动下标（相等的话同时后移，防止重复），最终完成顺序输出丑数|
|:star:[306. 累加数](https://leetcode-cn.com/problems/additive-number/)|方法一：利用`istringstream`将`string`转换成`long long`。方法二：**利用字符串的大数加法去处理溢出**|
|[313. 超级丑数](https://leetcode-cn.com/problems/super-ugly-number/)|**n指针归并**，主要思想和264一样|
|[326. 3的幂](https://leetcode-cn.com/problems/power-of-three/)|如果一个数num是3的幂，那么必然有`log3(num)`为整数，那么可以通过**换底公式**得出`log10(num)/log10(3)`，如果运算结果是整数，那么就是3的幂。向下取整的函数：`floor()`|
|[342. 4的幂](https://leetcode-cn.com/problems/power-of-four/)|方法一：换底公式，这个方法适用于所有判断某个数是不是n的幂。方法二：先判断这个数是不是2的幂，如果是，再看这个数对3取余是不是为1，因为4的幂次对3取余必为1|
|[365. 水壶问题](https://leetcode-cn.com/problems/water-and-jug-problem/)|巧的一逼，不想去想了|
|[367. 有效的完全平方数](https://leetcode-cn.com/problems/valid-perfect-square/)|和69题的方法一样，**二分查找**|
|[384. 打乱数组](https://leetcode-cn.com/problems/shuffle-an-array/)|**洗牌算法**：具体做法就是遍历每一个位置，然后和大于等于当前位置的一个位置上的数交换|
|[400. 第N个数字](https://leetcode-cn.com/problems/nth-digit/)|考察了对于数字的敏感程度，涉及到取余、定位数字的位数，定位具体数字等操作，细节很多|
|:fire::star:[504. 七进制数](https://leetcode-cn.com/problems/base-7/)|**十进制转换为其他进制--->除留取余法，然后逆置**|
|[670. 最大交换](https://leetcode-cn.com/problems/maximum-swap/)|之多交换一次字符串表示的数字中的两个数字，使得数字最大。先排序，然后找出两个数字第一个不同的位，就是待交换的数字|
|:star:[842. 将数组拆分成斐波那契序列](https://leetcode-cn.com/problems/split-array-into-fibonacci-sequence/)|**为预防当字符串转整型出现溢出，可以在操作前判断是否溢出**|

## 排序

> 1.出现字典序之类的要求

|题目|知识点|讲解|
:-|:-|:-|
|[324. 摆动排序 II](https://leetcode-cn.com/problems/wiggle-sort-ii/)|要求把数字排列成`nums[i]<nums[i+1]>nums[i+2]<...`。可以考虑把串数字先排序，然后再一分为二，然后交替插入新的数组中，陷阱在于如果前后两个数组出现了相同的数字，会导致最终结果出现多个相同数字相邻的情况|
|[327. 区间和的个数](https://leetcode-cn.com/problems/count-of-range-sum/)|方法一：使用的multise容器和它的方法lower_bound、upper_bound、distance。**通过multiset无序转有序，在multiset中使用二分搜索**。方法二：**利用归并排序思想**，没做。这题很难|
|[524. 通过删除字母匹配到字典里最长单词](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)|**先将字符串按长度和字典序排序**，然后利用双指针去匹配。这道题一开始往滑动窗口和Hash上去想了，没有想到先要排序，失败！|
|:star:[1727. 重新排列后的最大子矩阵](https://leetcode-cn.com/problems/largest-submatrix-with-rearrangements/)|**贪心+排序+数组，85题的简化版**，最关键在于如何表示第`j`列的高度，因为矩阵中某一列中的‘1’不是连续的。基本指导思想还是枚举高度|

## 前缀和

> 1.前缀和的数组下标是从1开始的，如果数组下标也是从1开始的，那么计算第i到j的前缀和：`preSum[j] - preSum[i - 1]`；如果数组下标是从0开始的，计算下标i到j的前缀和：`preSum[j + 1] - preSum[i]`
> 2.二维前缀和：`dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1] - dp[i - 1][j - 1]`

|题目|知识点|讲解|
:-|:-|:-|
|:star:[303. 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/)||
|:star:[304. 二维区域和检索 - 矩阵不可变](https://leetcode-cn.com/problems/range-sum-query-2d-immutable/)||
|:star:[523. 连续的子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum/)|**前缀和 + Hash(值和下标的映射) + 数学**，`(preSum[i] - preSum[j]) % k == 0`相当于`preSum[i] %  k == preSum[j] % k`|
|:star:[1314. 矩阵区域和](https://leetcode-cn.com/problems/matrix-block-sum/)||
|:star:[1664. 生成平衡数组的方案数](https://leetcode-cn.com/problems/ways-to-make-a-fair-array/)|创建**奇数项的前缀和**和**偶数项的前缀和**，主要难点在奇偶前缀和数组所代表的意义，先来考虑一下普通的前缀数组所代表的意义：`nums[i],0<=i<=n - 1`，`preSum[i],0<=i<=n`，`preSum[i]`有两种解释的方法：1.原数组第i项之前的前缀和（i = 0, 1, ...., n）2.用原数组的下标访问前缀和数组，原数组前i项（不包括`nums[i]`）的前缀和。   `oddPreSum[i],0 <= i <= n`表示原数组中前i项（不包括`nums[i]`）中奇数的前缀和|

## 设计
|题目|知识点|讲解|
:-|:-|:-|
|:one::star:[380. 常数时间插入、删除和获取随机元素](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/)|利用**Hash(建立数据与下标的映射)+数组(保存数据，通过交换实现删除)** ，实现插入和删除的O(1)时间复杂度|
|:star:[622. 设计循环队列](https://leetcode-cn.com/problems/design-circular-queue/)|**1.如果判空和判满？--> buffer大小设置为`k+1`，`head==tail`为空，`（tail+1)%n==head`为满。2.如何获取队尾元素? --> tail指向的是下次可插入位置，所以要取前一个位置，要循环取:`buffer[(tail - 1 + n) % n]`**。|
|[641. 设计循环双端队列](https://leetcode-cn.com/problems/design-circular-deque/)|和622差不多|
|[707. 设计链表](https://leetcode-cn.com/problems/design-linked-list/)|一定要注意`tail`结点的移动，不要粗心大意|

## 蓄水池抽样算法

> 适用场景：当内存无法加载全部数据时，如何从包含未知大小的数据流中随机选取k个数据，并且要保证每个数据被抽取到的概率相同

|题目|知识点|讲解|
:-|:-|:-|
|[382. 链表随机节点](https://leetcode-cn.com/problems/linked-list-random-node/)|以等概率获取**一个**长度未知的链表中的节点值|

## Morris算法
> ①没有左子树，则直接**遍历**该节点，然后走到右儿子
> ②有左子树，则找前驱节点p。
	> 若`p->right == nullptr`，则`p->right = root; root = root -> left`
	> 否则 `p -> right = nullptr;`，**遍历**`root`，`root = root -> right;`
	
|题目|知识点|讲解|
:-|:-|:-|
|:two:[99. 恢复二叉搜索树](https://leetcode-cn.com/problems/recover-binary-search-tree/)|Morris遍历利用的是树的叶节点左右孩子为空（树的大量空闲指针），实现空间开销的极限缩减。|[1.Morris算法讲解](https://leetcode-cn.com/problems/recover-binary-search-tree/solution/yi-wen-zhang-wo-morrisbian-li-suan-fa-by-a-fei-8/) [2.应用](https://leetcode-cn.com/problems/recover-binary-search-tree/solution/zhong-xu-bian-li-shuang-zhi-zhen-zhao-ni-xu-dui-mo/)|

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
|[189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)|**将数组循环右移k位**， 有一个巧妙的方法叫三次翻转法：①先把整个数组翻转②再把前k个元素翻转③最后再翻转后n-k个元素|
|:star:[289. 生命游戏](https://leetcode-cn.com/problems/game-of-life/)|矩阵中某个位置的状态如果发生改变，那么这种题的解法一般是**两次遍历这个矩阵**。第一次遍历时，**用一个不可能在矩阵中出现的中间值来保存状态的变化**（这样在此次遍历时，不影响其他位置的判断）；第二遍遍历时，把中间刷新为变化后应该变成的值|
|[303. 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/)|利用**前缀和**技巧提高查询区间和的速度|
|:star:[442. 数组中重复的数据](https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/)|**将数组元素映射为数组下标，原地取反表示已经被访问过**，要注意这个条件`1 ≤ a[i] ≤ n (n = 数组大小)的整型数组`|
|[448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)|和**442**使用了相同的思想|
|[463. 岛屿的周长](https://leetcode-cn.com/problems/island-perimeter/)|常规方法是DFS。但是可以利用**岛屿数量和相邻的边数计算周长**|
|:fire::star:[498. 对角线遍历](https://leetcode-cn.com/problems/diagonal-traverse/)|技巧性极度强|
|:star:[566. 重塑矩阵](https://leetcode-cn.com/problems/reshape-the-matrix/)|**将一维矩阵转换成任意m * n的矩阵：`matrix[i / col][i % col] = nums[i]`**|
|:star:[605. 种花问题](https://leetcode-cn.com/problems/can-place-flowers/)|**防御性编程思想：向首尾添加标记处理边界问题**|
|[665. 非递减数列](https://leetcode-cn.com/problems/non-decreasing-array/solution/)|以左中右三个数字为单位去考虑问题，这题很恶心，判断条件不好想|

## 位操作

|题目|知识点|
:-|:-|
|[102. 二叉树的层序遍历](https://leetcode-cn.com/problems/binary-tree-level-order-traversal/)|这个题的要求就是全部访问完二叉树的一层之后再去访问下一层，可以先记录当前需要访问的这层的个数，然后只从队列中取出相应个数个节点访问|
|[107. 二叉树的层次遍历 II](https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/)|和上一个题一样，最后利用reverse函数翻转结果|
|[136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)|**利用异或操作的交换律和结合律**，0异或一个数还是那个数，一个数异或自己为0。重复的数字出现了两次|
|[137. 只出现一次的数字 II](https://leetcode-cn.com/problems/single-number-ii/)|重复的数字出现了3次，那么把每个数字都看成32位二进制的形式，如果所有数字的出现了3次，那么每一列1的个数一定是3的倍数。之所以有的列不是三的倍数，是因为只出现一次的数贡献出了1。注意：双目的位运算符的优先级是大于单目位运算符的优先级的|
|[190. 颠倒二进制位](https://leetcode-cn.com/problems/reverse-bits/)|翻转一个32位二进制数|
|[191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)|方法一：每次都去判断这个数的最后一位是不是1。方法二：**每次都将这个数的最后一个1置0，n = n & (n - 1)**，在二进制表示中，数字 n中最低位的 1 总是对应 n - 1中的 0|
|[201. 数字范围按位与](https://leetcode-cn.com/problems/bitwise-and-of-numbers-range/)|连续范围内多个数字做位与操作。因为在位与运算中，为1的位是越位与越少的，而且最终位与的结果中为1的那个位在所有数字中的那个位置都为1。**规律：找出首尾两个数字相同的前缀，然后再左移相应的位数**|
|[231. 2的幂](https://leetcode-cn.com/problems/power-of-two/)|如果一个数是二的幂，那么这个数的二进制的第一位必为1，其余位为0。则n - 1的首位为0，其余位为1|
|[260. 只出现一次的数字 III](https://leetcode-cn.com/problems/single-number-iii/)|因为有两个只出现一次的数，如果我们把原数组分成两个数组，出现一个的那两个数分别在这两个数组中，那么在这两个数组内做异或运算，那么就能得到只出现一次的那个数。关键点在于如何找到第一个为1的位置，构造一个数，把这个位置1，其余位置0|
|:star:[318. 最大单词长度乘积](https://leetcode-cn.com/problems/maximum-product-of-word-lengths/)|这道题最难的点在于如何判断两个单词是否不包含相同字母。一个int类型数有32位，26个英文字母每个对应一位，把单词中所有字母的相应位置1，然后两个单词做位与运算，如果结果是0，说明包含的字母不存在相同的|
|:star:[371. 两整数之和](https://leetcode-cn.com/problems/sum-of-two-integers/)|**两数相与相当于是做了不进位加法；两数异或再右移一位相当于计算出两数加法的进位**，将相与和异或右移一位的结果相加知道进位为0，就得到了最终结果。至于为什么减法也能当加法来做，这归功于**补码**|
|:star:[405. 数字转换为十六进制数](https://leetcode-cn.com/problems/convert-a-number-to-hexadecimal/)|**模板题，C++不允许对负数执行移位运算，在对负数进行移位运算的时候需要把int转换成unsigned int**|
|:star:[476. 数字的补数](https://leetcode-cn.com/problems/number-complement/)|**1.构造一个n位全1的数字t。2.用这个数字和原数字做异或操作**，这样就可以得到原数字的补码。**正整数不包括0**|

## 树

> 1.满二叉树：每个结点都有两个或零个子结点；
2.完美二叉树：除了最后一层，每个节点都有两个子节点；
3.完全二叉树：除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置

|题目|知识点|
:-|:-|
|:two::star:[94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)|**颜色标记法**,白色表示没有访问过，灰色表示访问过|
|:one::star:[95. 不同的二叉搜索树 II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)|这道题用了递归的思想，非常非常巧妙，重点看。还可以动态规划的思想做，但我没看|
|:two::fire:[98. 验证二叉搜索树](https://leetcode-cn.com/problems/validate-binary-search-tree/)|方法一：二叉搜索树中序遍历为有序。方法二：**当前节点值大于左子树最大值，小于右子树最小值**|
|:star:[101. 对称二叉树](https://leetcode-cn.com/problems/symmetric-tree/)|递归的思路没想出来|
|[104. 二叉树的最大深度](https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/)|经典题目|
|:one::star:[105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|前序遍历的第一个节点一定是二叉树的根节点，然后在中序遍历中寻找根节点的位置，可以把二叉树分为左右两个子树，并且还可以知道左右子树所含节点的个数。然后再对左右子树进行相同的操作。这就是分治的思想。`pivotIndex - inLeft`|
|:one::star:[106. 从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)|后序遍历中最后一个节点一定是二叉树的根节点，然后在中序遍历中寻找根节点的位置，可以把二叉树分为左右两个子树。整体思想和上题一样。`inRight - pivotIndex`|
|[108. 将有序数组转换为二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/)|分治思想，利用区间的变换，每次都取区间的中点作为根节点。和105、106题一样的思想|
|[109. 有序链表转换二叉搜索树](https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/)|分治思想，和前一道比只是将连续结构换成了链式结构，需要分割链表|
|:star:[111. 二叉树的最小深度](https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/)|经典题目|
|:one::star:[114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)|从树的结构上找规律|
|:two::star:[**116. 填充每个节点的下一个右侧节点指针**](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/)|这个题可以转化成如何成对访问完美二叉树的两两相邻节点。空间复杂度为O(1)的迭代和递归做法都非常巧妙 |
|:one::star:[**117. 填充每个节点的下一个右侧节点指针 II**](https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/)|用了链表的思想将每一层的节点串在一起|
|:two::star:[124. 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)|**利用全局变量特判保证不改变递归函数的整体功能**，和**687题类似**|
|:star:[129. 求根到叶子节点数字之和](https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/solution/)|方法一：树的路径回溯(进入到空节点退出，不还原)；分治（写法比较巧妙），遇到空节点，该条路径直接为0|
|:star:[144. 二叉树的前序遍历](https://leetcode-cn.com/problems/binary-tree-preorder-traversal/)|**颜色标记法，入栈顺序和访问顺序相反**|
|:star:[145. 二叉树的后序遍历](https://leetcode-cn.com/problems/binary-tree-postorder-traversal/)|**颜色标记法**|
|:one:[230. 二叉搜索树中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/)|考察了二叉搜索树和中序遍历结果和第K小元素之间的关系：二叉搜索树中第K小的元素就是中序遍历中第K个访问到的节点值|
|[235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)|这个题要利用二叉排序树本身的性质，如果当前节点的大小位于两个目标节点之间，那么这个节点就是最近的公共节点，如果两个节点都比当前节点大，那么LCA一定在当前节点的右子树；如果两个节点都比当前节点小，那么LCA一定在当前节点的左子树|
|[257. 二叉树的所有路径](https://leetcode-cn.com/problems/binary-tree-paths/)|分治和DFS都可以做|
|:star:[297. 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)|将一颗二叉树序列化，有前序和中序两种序列可以选择，然后又可以通过序列化的结果重构这颗二叉树。**前序序列化充分利用了分治的思想**，十分巧妙|
|[331. 验证二叉树的前序序列化](https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/)|方法一：利用了297的思想，看该序列能否重构一个二叉树|
|:fire::star:[450. 删除二叉搜索树中的节点](https://leetcode-cn.com/problems/delete-node-in-a-bst/)|分三种情况：1.待删除结点是叶子结点，直接将该结点赋值为`nullptr`。2.待删除结点只有左子树或右子树，将左儿子或右儿子赋值给待删除结点。3.如果既有左子树又有右子树，那就找待删除结点的后继结点，然后将后继结点的值赋给待删除结点，然后递归删除后继结点的值|
|[501. 二叉搜索树中的众数](https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/)|**可以想象为在有序数组里面找众数**，利用BST的性质，中序遍历的结果是递增序列，设置**前驱结点**|
|[563. 二叉树的坡度](https://leetcode-cn.com/problems/binary-tree-tilt/)|我写的代码很冗余，参考代码写的很漂亮|
|:fire::star:[572. 另一个树的子树](https://leetcode-cn.com/problems/subtree-of-another-tree/)|1.要么两个树相等，要么这个树是左数的子树3.要么这个树是右树的子树|
|:star:[687. 最长同值路径](https://leetcode-cn.com/problems/longest-univalue-path/)|**利用全局遍历去处理递归中的特殊情况**。与**124题**有着一样的思想。这道题对于递归分治的思想考察的很到位|
|[701. 二叉搜索树中的插入操作](https://leetcode-cn.com/problems/insert-into-a-binary-search-tree/)|经典题目，只要插到正确的位置就行了，不要去考虑平衡问题|


## 字符串

|题目|知识点|
:-|:-|
|[557. 反转字符串中的单词 III](https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/)|考察了有关于reverse和vector的迭代器的使用|
|:star:[415. 字符串相加](https://leetcode-cn.com/problems/add-strings/)|模板题|
|:star:[459. 重复的子字符串](https://leetcode-cn.com/problems/repeated-substring-pattern/)|巧妙方法：将字符串加倍，然后从第一个位置寻找原字符串，这个方法太巧妙。常规方法：利用KMP里的思想，没做|
|:fire:[468. 验证IP地址](https://leetcode-cn.com/problems/validate-ip-address/)|这道题有**split()函数的模板写法**。本题需要考虑很多细节，想去判断一个字符串合不合法，**可以去想什么时候该字符串不合法**，反向思考简化判断过程|
|[696. 计数二进制子串](https://leetcode-cn.com/problems/count-binary-substrings/)|很巧妙，要从字符串自身结构入手优化|
|:two::star:[1657. 确定两个字符串是否接近](https://leetcode-cn.com/problems/determine-if-two-strings-are-close/)|给出两个操作，判断能不能将字符串转化为另一个字符串。**考察字符串转换条件**|
|:star:[5662. 满足三条件之一需改变的最少字符数](https://leetcode-cn.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/)|**如果字符串中只涉及26个英文字母，可以考虑直接暴力枚举**|



## 哈希表

> 1、判断一些数中有没有出现某个数

|题目|知识点|
:-|:-|
|:fire:[1. 两数之和](https://leetcode-cn.com/problems/two-sum/)|经典哈希问题|
|:one::star:[30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)|**双哈希**，第一个hash记录所有字典里的单词，第二个哈希记录当前遍历的单词。这个题有很多细节，很容易错|
|[30. 串联所有单词的子串](https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/)|给出多个长度相同的单词，找包含这些单词的所有**连续子串**，因为单词之间的排列可以有很多种，所以很难去进行字符串之间的匹配，所以可以转而去考虑每个单词出现的次数，如果当前匹配的子串目标单词出现的次数和字典中单词出现的次数是一样的话，就说明匹配成功|
|:two::star:[36. 有效的数独](https://leetcode-cn.com/problems/valid-sudoku/)|board中的整数被限制在0~9中，因此可以分别建立哈希表来存储任意一个数在相应维度上是否出现过。这道题的主要难点在于如何判断board[i][j]是否在其属于的哪个3×3的表中出现过。9×9的矩阵可以理解为9个3×3的矩阵，要做的就是通过i,j确定board[i][j]在哪一个3×3的矩阵里，公式就是j / 3 + (i / 3) * 3|
|[49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)|所谓的异构词，就是按字典序排序后相同的字符串，所以先排序，然后再哈希。这种类似的题周赛出现过，要从字符串本身找出规律|
|:one::fire::star:[128. 最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/)|经典哈希题目，这个题的思想要熟练|
|:two::fire:[138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)|双哈希；没想到用vector保存新的链表结点并用下标做映射|
|:one:[187. 重复的DNA序列](https://leetcode-cn.com/problems/repeated-dna-sequences/)|经典题目|
|:star:[290. 单词规律](https://leetcode-cn.com/problems/word-pattern/)|**双哈希**，需要考虑很多边界条件|
|:one::star:[336. 回文对](https://leetcode-cn.com/problems/palindrome-pairs/)|又考察了和利用回文串的自身性质：**如果一个字符串是回文串，那么必然有一个对称中心，沿着这个对称中心依次向两边扩展得到的连续字串还是回文串，并且，和中心对称的左右两个字串的顺序是相反的**。那么，我可以依次选择一个字符串的所有位置当作对称中心，将原字符串分为左右两个部分，当其中一边是回文串的时候，看字典中是否存在另一边逆序的字符串，如果存在，就可以累加得到一个新的回文串|
|:two:[350. 两个数组的交集 II](https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/)|经典题目|
|[352. 将数据流变为多个不相交区间](https://leetcode-cn.com/problems/data-stream-as-disjoint-intervals/)|**两个order_map存储区间**，左端点->右端点，右端点->左端点，当插入一个点进去的时候要去判断是否和左右两个区间相交，如果相交，合并区间后要删除之前的映射关系|
|[383. 赎金信](https://leetcode-cn.com/problems/ransom-note/)|遇到英文字母和其出现个数的映射时，可以直接用vector来存储映射关系|
|:one:[409. 最长回文串](https://leetcode-cn.com/problems/longest-palindrome/)|一个字母可以构成`n / 2`对，也就是`(n / 2) * 2`个，如果还有剩余字符，可以放到最中间，总字符数加1|
|:two::fire::star:[454. 四数相加 II](https://leetcode-cn.com/problems/4sum-ii/)|经典哈希题目，先计算出前两个数的所有可能的和，并保存在map中；再遍历后两个数的和，看是否等于前两个数的和的相反数|
|[429. N叉树的层序遍历](https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/)|记录每一层的数量统一遍历|
|:one::fire::star:[454. 四数相加 II](https://leetcode-cn.com/problems/4sum-ii/)|相当于从四个等长数组中每个选一个数，判断四数之和是否为0。**利用map存放前两个数组每个数相加的和(key)，val为和出现的次数，然后再去计算第三个第四个数组中所有数字的和，看其相反数有没有出现在map中**，这个题和18题的区别在于，这道题**不用去重**，所以可以使用hash|
|:star:[652. 寻找重复的子树](https://leetcode-cn.com/problems/find-duplicate-subtrees/)|**树的序列化+哈希**,先通过树的前序遍历构造每一个子树的序列，构造方式为：`string str = to_string(root -> val) + " " + inOrder(root -> left) + " " + inOrder(root -> right)`，结点为`nullptr`的话就返回`#`|
|[1726. 同积元组](https://leetcode-cn.com/problems/tuple-with-same-product/)|454题的改编版本，需要用到排列组合的思想|
|:star:[5642. 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)|1.两数之和的变种。加入哈希的方式是**先查找再加入**，很好的哈希题目|

## 前缀和与哈希
|题目|知识点|
:-|:-|
|:two:[525. 连续数组](https://leetcode-cn.com/problems/contiguous-array/)|用前缀和的思想保存0和1的差值，如果在遍历的过程中出现相同的差值，那么这两个差值的下标只差就是具有相同0和1连续子数组的长度。脑筋急转弯题|
|:star:[523. 连续的子数组和](https://leetcode-cn.com/problems/continuous-subarray-sum/)|**前缀和 + Hash(值和下标的映射) + 数学**，`(preSum[i] - preSum[j]) % k == 0`相当于`preSum[i] %  k == preSum[j] % k`|
|[554. 砖墙](https://leetcode-cn.com/problems/brick-wall/)|难点在于转化题意|
|:two::fire::star:[560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)|**哈希+前缀和**；如果直接计算完前缀和然后两两前缀和相减会超时；这道题的技巧在于在计算前缀和过程中，直接去搜索已经计算过的并且符号要求的前缀和|
|[974. 和可被 K 整除的子数组](https://leetcode-cn.com/problems/subarray-sums-divisible-by-k/)|和523类似，涉及一点数学知识。难点在于当负数对正数做取余操作怎么处理，比如`-1 % 4`，C++中结果为`-1`，但实际上要给`-1`加上`4`才是最终结果|



## 链表

> 考察角度：链表结构、双指针、分治
> 记录：109

|题目|知识点|
:-|:-|
|:fire:[2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)|模拟竖式加法，要设置一个**进位**，要注意最后可能需要添加一个值为1的节点|
|:one::star:[19. 删除链表的**倒数**第N个节点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)|关键在于如何**一次遍历**，这时候可以使用**快慢指针**|
|:one::star::fire:[23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)|方法一：**归并**。方法二：**堆**|
|:star:[24. 两两交换链表中的节点](https://leetcode-cn.com/problems/swap-nodes-in-pairs/)|需要熟练掌握的链表操作|
|:one::star::fire:[25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)|非常好的题，要熟练掌握。递归和迭代两种方法|
|[61. 旋转链表](https://leetcode-cn.com/problems/rotate-list/)|边界条件需要注意一下，很容易出错|
|:one:[82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/)|有迭代和递归两种写法，都比较巧妙，和上一个题思想类似|
|:one::star:[83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)|递归写法**非常巧妙**|
|:two::fire:[138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)|双哈希|
|[141. 环形链表](https://leetcode-cn.com/problems/linked-list-cycle/)|快慢指针|
|:star::fire::one:[142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)|技巧性强，公式要记住。`slow = n * b; k = a + n * b`|
|:one:[143. 重排链表](https://leetcode-cn.com/problems/reorder-list/)|一头一尾取元素相连，由于想取得尾元素每次都需要遍历链表，所以这里可以优化。**递归方法相当巧妙；考察了求链表中点，逆置链表，交差合并链表**|
|:one::star:[148. 排序链表](https://leetcode-cn.com/problems/sort-list/)|**链表的归并排序(bottom to up)**，链表的合并和切分操作要熟练掌握|
|[203. 移除链表元素](https://leetcode-cn.com/problems/remove-linked-list-elements/)|**递归解法相当巧妙**|
|:fire:[206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)|迭代法：设置pre,cur,next；递归：边界条件，调用递归函数的位置|
|:one:[237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)|直接删除待删除结点（只传入待删除结点），巧妙|
|:one:[430. 扁平化多级双向链表](https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/)|考察链表的递归|
|[876. 链表的中间结点](https://leetcode-cn.com/problems/middle-of-the-linked-list/)|常用操作，一定要很快写出来|


## 图
|题目|知识点|
:-|:-|
|[133. 克隆图](https://leetcode-cn.com/problems/clone-graph/)|考察了**无向无权图的深搜和广搜**，图在遍历的时候一定要记录已经被访问过的节点|
|[207. 课程表](https://leetcode-cn.com/problems/course-schedule/)|考察了图的拓扑排序。**拓扑排序的应用场景：** 任务调度计划，课程安排。**拓扑排序的作用：** ①得到一个拓扑序，不唯一。②用来检测有向图中是否存在环|
|[210. 课程表 II](https://leetcode-cn.com/problems/course-schedule-ii/)|解决方法和第一题一样，只是本题让输出拓扑序|
|[310. 最小高度树](https://leetcode-cn.com/problems/minimum-height-trees/)|**利用拓扑排序思想**，还利用了无向图转有向图，邻接矩阵表示图。所谓最小高度树，就是从无向图中一个节点的任意方向出发，到叶子节点所走的步数最小的节点。**这样的节点不是一个就是两个**。|
|[329. 矩阵中的最长递增路径](https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/)|**利用拓扑排序的思想**,以节点的出度为0作为加入队列的条件|
|[332. 重新安排行程](https://leetcode-cn.com/problems/reconstruct-itinerary/)|考察**欧拉路径**的生成算法|

## 单调栈


> 1.涉及到按照字典序选择元素
> 2.找第一个比当前元素大或小的元素

|题目|知识点|
:-|:-|
|:three::fire::star:[84. 柱状图中最大的矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)|核心思想是**枚举高度**，找到以某个高度为中心，左右两边第一个小于该高度的位置，这样就可以得到宽度|
|:two::fire::star:[85. 最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)|84题升级版，主要在于**通过递推的思想预处理一个表示矩阵高度的数组**，然后枚举高度数组的下边界，使用84题的方法计算最大面积|
|:one:[316. 去除重复字母](https://leetcode-cn.com/problems/remove-duplicate-letters/)|利用了和402一样的思想，由于**去掉重复字母后要保证整个字符串相对顺序不被改变而且字典序最小**，那么这个时候就要考虑单调栈了|
|:two::star:[321. 拼接最大数](https://leetcode-cn.com/problems/create-maximum-number/)|这个题是从两个vector中选出K个数字，要求组成的数字最大。**分治+单调队列**,这道题需要考虑的细节比较多，有难度。按字典序比较两个序列大小的函数`bool lexicographical_compare(it1_begin(), it1_end(), it2.begin(), it2.end())`|
|:star:[402. 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/)|**根据字典序或数字大小进行选择或删除---->单调栈**。在一个字符串表示的数中移除K位，使得数字最小。一开始我用的回溯，但是超时了，原因在于我没有利用题中的有关信息，因为想让某个数字最小，只要让这个数字的最高位尽可能小就可以了。所以使用了**单调栈**进行优化，如果后一个数字大于前一个数字，那么就将前一个数字出栈|
|[496. 下一个更大元素 I](https://leetcode-cn.com/problems/next-greater-element-i/)|核心就是找出在位置`i`后第一个比`nums[i]`大的数字，维护一个单调递减队列|
|[503. 下一个更大元素 II](https://leetcode-cn.com/problems/next-greater-element-ii/)|关键在于处理**循环数组**，可以在原数组后再补一个原数组，但不用真的去补，只需要用取余操作模拟|
|[556. 下一个更大元素 III](https://leetcode-cn.com/problems/next-greater-element-iii/)|将某个字符串表示的数字变成刚好比这个字符 串大的数字，单调队列可以稍微优化搜索过程|
|:one::fire:[739. 每日温度](https://leetcode-cn.com/problems/daily-temperatures/)|求第一个比当前位置数大的数的下标。从后往前遍历，这样代码写出来更简洁，栈里面保存的是下标|
|:one::star:[1754. 构造字典序最大的合并字符串](https://leetcode-cn.com/problems/largest-merge-of-two-strings/)|和402的思想一样，但是周赛的时候我想复杂了，直接比较两个字符串的字典序就行了，没有必要找出第一个不相等的字符然后再比较大小，太愚蠢了|
|[5614. 找出最具竞争力的子序列]|和402的思想一摸一样，但是我周赛没想到，一直在往回溯的方向去想|
## 单调队列

> 使用deque，保存的是元素的下标

|题目|知识点|
:-|:-|
|:fire::star:[239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)|利用双端队列，队头保持最值。要注意的点主要在于出队的时候，先把当前元素`nums[i]`入队，然后再利用`i - k(窗口大小) + 1`得到本来待出队元素的下标（因为队列里保存的是经过处理过的单调数据，要出队的那个数可能已经出队了）,如果这个数和队头元素相等，那么就出队队头元素。**这种方法也能求窗口里的最小值**|
|[5631. 跳跃游戏 VI](https://leetcode-cn.com/problems/jump-game-vi/)|**单调队列优化**|

## 栈
|题目|知识点|
:-|:-|
|[224. 基本计算器](https://leetcode-cn.com/problems/basic-calculator/)|方法一：中缀表达式转后缀表达式，然后再计算后缀表达式。方法二：双栈法，一个栈放运算数，一个栈放运算符，在遍历的过程中就直接计算|
|[227. 基本计算器 II](https://leetcode-cn.com/problems/basic-calculator-ii/)|整体思路和上一个题一样，主要注意**运算符的优先级导致的计算顺序问题**|

## 堆

> 堆：堆的底层实现是一颗完全二叉树（除最后一层外，其余每一层都有左右子节点，最后一层从左到右依次排列）
> 如何手写一个堆？
> 1.插入一个数：`heap[++size] = x; up(size)`
> 2.求集合中的最小数：`heap[1];`
> 3.删除最小值：`heap[1] = heap[size]; size--; down(1);`
> 4.删除任意一个元素：`heap[k] = heap[size]; size--; down(k); up(k);`
> 5.修改任意一个元素：`heap[k] = x;down(k); up(k);`

|题目|知识点|
:-|:-|
|[373. 查找和最小的K对数字](https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/)|这道题主要难点在于怎么写priority_queue的cmp函数，**大堆小于号，小堆大于号**|
|:star:[692. 前K个高频单词](https://leetcode-cn.com/problems/top-k-frequent-words/)|这道题有助于理解优先队列的排序函数的本质。排序函数是比较两个参数的**优先级**，**如果返回值是true,表明第一个参数优先级大**，反之第二个参数优先级大。在优先队列中，**优先级大的元素在堆底部，优先级小的元素在堆顶**|
|:one::star:[1642. 可以到达的最远建筑](https://leetcode-cn.com/problems/furthest-building-you-can-reach/)|**贪心+小根堆**|
|:star:[5638. 吃苹果的最大数目](https://leetcode-cn.com/problems/maximum-number-of-eaten-apples/)|这道题用堆解决的很巧妙，我没有想到，相当于是**利用堆来对区间进行排序**|

## 并查集

> 1.合并两个集合
> 2.判断两个元素是不是在一个集合中
> 3.返回集合的大小
> 4.判断二叉树中是否有环
>  基本原理：每个集合用一棵树来表示。树根的标号就是整个集合的编号，每个节点都存储他的父节点,p[x]表示x的父节点
> 问题一：如何判断树根？if(p[x] == x)
> 问题二：如何求x的集合编号？while(p[x] != x) x = p[x]
> 问题三：如何合并两个集合：px是编号x的集合，py是编号y的集合。p[x] = y

|题目|知识点|
:-|:-|
|[684. 冗余连接](https://leetcode-cn.com/problems/redundant-connection/)|判断**无向图中是否存在环**，如果两个集合的代表元素相同，则说明有环|
|[685. 冗余连接 II](https://leetcode-cn.com/problems/redundant-connection-ii/)|判断**有向图中是否有环,但拓扑排序不适合用于解决这个问题**，因为题目中的要求是返回一条需要删除的边。这道题可以转化为684，因为题中说“附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边”，所以每个结点的入度要不就是全是1，要么有一个节点的入度为2，其他的都是1。|
|:star:[5650. 执行交换操作后的最小汉明距离](https://leetcode-cn.com/problems/minimize-hamming-distance-after-swap-operations/)|**并查集+哈希**；并查集记录连通块的下标，用哈希记录每个祖宗结点代表的联通集合中的元素值|

## Trie树
> 1.统计字符串出现的次数
> 2.查找某个字符串的前缀

|题目|知识点|
:-|:-|
|[208. 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)|前缀树适用于两个场景：①统计每个单词出现的次数。②查找某个单词的前缀|
|[212. 单词搜索 II](https://leetcode-cn.com/problems/word-search-ii/)|题目要求在一个矩阵中搜索多个单词是否存在于矩阵中。基本方法是遍历所有待搜索单词，然后一个个单词去在矩阵中用DFS去搜索。进阶方法是：**把所有待搜索单词放到一个前缀树中，用word来代替flag标识单词的结束，然后在前缀树的基础上使用回溯算法去搜索单词**|
|[336. 回文对](https://leetcode-cn.com/problems/palindrome-pairs/)|前缀树可以做，但我没做|
|[421. 数组中两个数的最大异或值](https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/)|**1.每次得到一个数的最高位2.使用异或实现0和1的相互转换3.通过每一位来构造一个数**。Trie的孩子结点中存放0或1，深度是32.这样每个32位数就都能放Trie里面存储了。**所谓两个数异或值最大，就是希望另一个数尽可能和自己每一位都不相同**|

## 线段树
|题目|知识点|
:-|:-|
|[307. 区域和检索 - 数组可修改](https://leetcode-cn.com/problems/range-sum-query-mutable/)|实现了线段树的构造、更新、求区间和三个操作|

## 不熟的高频题
|题目|知识点|
:-|:-|
|[5. 最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)|有一些细节还是不熟|
|[7. 整数反转](https://leetcode-cn.com/problems/reverse-integer/)|核心代码掌握了，但代码写的不够简洁，负数都一个数的取余结果是负数|
|[9. 回文数](https://leetcode-cn.com/problems/palindrome-number/)|不会巧妙做法|
|[11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)|脑筋急转弯，做法可以用反证法证明|
|[15. 三数之和](https://leetcode-cn.com/problems/3sum/)|核心思路知道，细节还是出问题|
|[17. 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)|不知道该怎么转化题意，直接往迭代那里去想了|
|[18. 四数之和](https://leetcode-cn.com/problems/4sum/)|去重有一点点问题，第二重循环去重的时候错了|
|[19. 删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/)|边界条件的处理有问题，就是删除倒数第一个结点的时候|
|[22. 括号生成](https://leetcode-cn.com/problems/generate-parentheses/)|**1.任意前缀中，`(` 个数大于等于`)`个数。2.左右括号数量相等**。模板题，没记住|



