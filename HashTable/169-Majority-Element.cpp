/*方法一：哈希*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxNum = 0, maxCount = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]] += 1;
            int count = mp[nums[i]];
            if(count > maxCount){
                maxCount = count;
                maxNum = nums[i];
            }
        }
        return maxNum;
    }
};

/*方法二：摩尔投票法*/
/*因为有一个数的个数是大于n/2的，所以其他数的个数的总和也没有这个数多*/

/*核心就是对拼消耗。

玩一个诸侯争霸的游戏，假设你方人口超过总人口一半以上，并且能保证每个人口出去干仗都能一对一同归于尽。最后还有人活下来的国家就是胜利。

那就大混战呗，最差所有人都联合起来对付你（对应你每次选择作为计数器的数都是众数），或者其他国家也会相互攻击（会选择其他数作为计数器的数），但是只要你们不要内斗，最后肯定你赢。

最后能剩下的必定是自己人。
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = nums[0];//当前诸侯
        int count = 1;//当前诸侯兵力

        for(int i = 1; i < nums.size(); i++){
            if(count == 0){//手下的兵都被打光了，换人
                cur = nums[i];
                count = 1;
                continue;
            }
            if(nums[i] == cur){//友军
                count++;
            }
            else if(nums[i] != cur){
                count--;
            }
        }
        return cur;//战到最后的人
    }
};