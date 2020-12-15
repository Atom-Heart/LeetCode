/*这个题拿到手毫无思路，完全不知道要怎么下手
*方法一（哈希表+最小堆）：x是一个存在于nums中的元素，如果存在一个长度为k且以x - 1结尾的子序列的话，那么x就可以和这个子序列组成长度为k + 1的新的子序列。但有可能有多个以x - 1结尾的子序列，那就选择一个长度最小
*的子序列（贪心，尽量让所有子序列的长度都大于3）。那么可以用key是以x结尾的子序列，value是该子序列的长度建立Hash，但又要求每次都选择长度最短的子序列，所以可以选择最小堆来维护value
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for(int i = 0; i < nums.size(); i++){
            /*不存在以nums[i] - 1结尾的子序列*/
            if(mp.find(nums[i] - 1) == mp.end()){
                mp[nums[i]].push(1);//创建一个长度为1且以nums[i]结尾的子串
            }
            else{
                /*修改成为以nums[i]结尾的子序列*/
                int len = mp[nums[i] - 1].top();
                mp[nums[i] - 1].pop();
                if(mp[nums[i] - 1].empty()) mp.erase(nums[i] - 1);
                mp[nums[i]].push(len + 1);
            }
        }

        for(auto it = mp.begin(); it != mp.end(); it++){
            if(it -> second.top() < 3) return false;
        }
        return true;
    }
};

/*方法二（双哈希表）*/
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt;//记录每个数的出现个数
        unordered_map<int, int> tail;//记录以nums[i]结尾且符合题意的子序列的个数

        for(int num : nums) cnt[num] += 1;

        for(int num : nums){
            /*num已经消耗完了*/
            if(cnt[num] == 0) continue;
            /*num - 1存在，可以组成新的子序列*/
            else if(cnt[num] > 0 && tail[num - 1] > 0){
                cnt[num]--;
                tail[num - 1]--;
                tail[num]++;
            }
            /*num不能和前面的子序列连上，但是可以和后面的数组成新的子序列*/
            else if(cnt[num] > 0 && cnt[num + 1] > 0 && cnt[num + 2] > 0){
                tail[num + 2]++;
                cnt[num]--;
                cnt[num + 1]--;
                cnt[num + 2]--;
            }
            /*num没有消耗完，而且和前后都无法组成新的子序列*/
            else{
                return false;
            }
        }
        return true;
    }
};