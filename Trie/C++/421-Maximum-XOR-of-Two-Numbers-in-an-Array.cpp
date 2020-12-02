class Solution {
public:
    struct TrieNode{
        TrieNode* child[2];
        TrieNode(){
            for(int i = 0; i < 2; i++){
                child[i] = nullptr;
            }
        }  
    };
    class Trie{
    public:
        Trie(){
            root = new TrieNode();
        }
        
        void insert(int num){
            TrieNode* ptr = root;
            for(int i = 31; i >= 0; i--){
                int bitVal = (num >> i) & 1;
                if(ptr -> child[bitVal] == nullptr){
                    ptr -> child[bitVal] = new TrieNode();
                }
                ptr = ptr -> child[bitVal];
            }
        }
        int findMax(int num){
            int ans = 0;
            TrieNode* ptr = root;
            /*每次获得32位数的最高位*/
            for(int i = 31; i >= 0; i--){
                int bitVal = (num >> i) & 1;
                int best = bitVal ^ 1;//得到该位的对立数，位操作很漂亮
                if(ptr -> child[best] == nullptr){
                    best ^= 1;//如果理想的数不存在于Trie中，那么就只能选择存在的那一个了
                }
                ans |= (best ^ bitVal) << i;//记录异或的结果
                ptr = ptr -> child[best];
            }
            cout<<ans<<endl;
            return ans;
        }
    private:
        TrieNode* root;
    };
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int ans = INT_MIN;
        for(int num : nums) t.insert(num);
        for(int num : nums){
            ans = max(t.findMax(num), ans);
        }
        return ans;
    }
};