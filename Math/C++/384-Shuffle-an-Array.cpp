/*洗牌算法：第一个位置可以从[1, n]个数里选一个，第二个位置从[2, n]个数里选一个，.......*/
/*具体做法就是遍历每一个位置，然后和大于等于当前位置之后的一个位置上的数交换*/
/**/
class Solution {
public:
    Solution(vector<int>& nums) {
        a = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> b = a;
        for(int i = 0; i < b.size(); i++){
            swap(b[i], b[i + random() % (b.size() - i)]);
        }
        return b;
    }
    vector<int> a;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */