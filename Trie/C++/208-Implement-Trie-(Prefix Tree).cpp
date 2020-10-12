struct TrieNode{
    TrieNode* child[26];
    bool is_end;
    TrieNode() : is_end(false){
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *ptr = root;
        for(int i = 0; i < word.size(); i++){
            int pos = word[i] - 'a';
            if(!ptr -> child[pos]){
                ptr -> child[pos] = new_node();
            }
            ptr = ptr -> child[pos];
        }
        ptr -> is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *ptr = root;
        for(int i = 0; i < word.size(); i++){
            int pos = word[i] - 'a';
            if(!ptr -> child[pos]){
                return false;
            }
            ptr = ptr -> child[pos];
        }
        return ptr -> is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        for(int i = 0; i < prefix.size(); i++){
            int pos = prefix[i] - 'a';
            if(!ptr -> child[pos]){
                return false;
            }
            ptr = ptr -> child[pos];
        }
        return true;
    }
private:
    TrieNode *root;
    TrieNode* new_node(){
        TrieNode* node = new TrieNode();
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */