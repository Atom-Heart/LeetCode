/*暴力*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    static bool cmp(pair<int ,int>& a, pair<int, int>& b){
        return a.second > b.second;
    }
    unordered_map<int, int> mp;
    void dfs(TreeNode* root){
        if(root == nullptr) return;
        mp[root -> val]++;
        dfs(root -> left);
        dfs(root -> right);
    }
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        dfs(root);
        /*相对map的val排序，先把map中的pair放到线性容器里*/
        vector<pair<int, int>> v;
        for(auto it = mp.begin(); it != mp.end(); it++){
            v.push_back(*it);
        }
        sort(v.begin(), v.end(), cmp);
        int n = v[0].second;
        for(int i = 0; i < v.size(); i++){
            if(v[i].second == n) ans.push_back(v[i].first);
            else break;
        }
        return ans;
    }
};

/*利用BST性质*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pre = nullptr;
    int maxCount = INT_MIN;
    int count = 0;
    vector<int> ans;
    vector<int> findMode(TreeNode* root) {
        if(root == nullptr) return {};
        InOrder(root);
        return ans;

    }
    void InOrder(TreeNode* root){
        if(root == nullptr) return;
        InOrder(root -> left);

        /*第一个结点*/
        if(pre == nullptr){
            count = 1;
        }
        /*当前结点值和前驱结点的值相等*/
        else if(root -> val == pre -> val){
            count++;
        }
        else{
            count = 1;//更新当前元素个数
        }

        if(count == maxCount){
            ans.push_back(root -> val);
        }
        else if(count > maxCount){
            maxCount = count;
            ans.clear();
            ans.push_back(root -> val);
        }
        pre = root;
        
        InOrder(root -> right);
    }
};