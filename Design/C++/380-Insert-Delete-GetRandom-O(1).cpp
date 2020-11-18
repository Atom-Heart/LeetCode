/*如果要求插入和删除操作的时间复杂度都是O(1)的，那么一般要想到Hash，unordered_map的建立映射和查询操作时间复杂度都为O(1)*/

/*unordered_map<数字,下标> */
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        /*val已经存在*/
        if(mp.find(val) != mp.end()) return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false;
        int num = nums.back();
        mp[num] = mp[val];//修改最后一个数的映射关系
        nums[mp[val]] = num;//用最后一个数字替换这个数
        mp.erase(val);//删除val的映射关系
        nums.pop_back();//删除最后一个数
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    unordered_map<int, int> mp;
    vector<int> nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */