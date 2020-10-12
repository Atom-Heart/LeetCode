/*自实现前缀树，用word代替flag表示一个单词的结束*/
struct TrieNode{
    string word;
    TrieNode* child[26];
    TrieNode(){
        for(int i = 0; i < 26; i++){
            child[i] = nullptr;
        }
    }
};

class Trie{
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* ptr = root;
        for(int i = 0; i < word.size(); i++){
            int pos = word[i] - 'a';
            if(ptr -> child[pos] == nullptr){
                ptr -> child[pos] = new TrieNode();
            }
            ptr = ptr -> child[pos];
        }
        ptr -> word = word;
    }
    TrieNode* root;
};

class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<string> ans;
        Trie* trie = new Trie();
        /*把所有单词都加入到前缀树中*/
        for(auto word : words){
            trie -> insert(word);
        }
        /*从矩阵的每个位置开始遍历*/
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                DFS(board, i, j, trie -> root, ans);
            }
        }
        return ans;
    }
    bool DFS(vector<vector<char>>& board, int x, int y, TrieNode* node, vector<string>& ans){
        char ch = board[x][y];
        int pos = ch - 'a';
        if(board[x][y] != '#' && node -> child[pos] != nullptr){//该字母在前缀树中存在
            board[x][y] = '#';//利用特殊符号标记该位置已经被访问过了
            node = node -> child[pos];//指针指向这个字母
            if(node -> word != ""){//如果这个字母是一个单词的结尾
                ans.push_back(node -> word);//加入到结果集中
                node -> word = "";//把这个单词置空，防止重复加入
            }
            for(int i = 0; i < 4; i++){
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                if(new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[0].size()){
                    if(DFS(board, new_x, new_y, node, ans)) return true;
                }
            }
        }
        else{
            return false;
        }
        board[x][y] = ch;//恢复矩阵
        return false;
    }
};