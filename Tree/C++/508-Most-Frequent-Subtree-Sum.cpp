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
    unordered_map<int, int> mp;
    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        int sum = root -> val + helper(root -> left) + helper(root -> right);
        mp[sum]++;
        return sum;
    }

    static bool cmp(const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root == nullptr) return {};
        vector<pair<int, int>> v;
        helper(root);
        for(auto it = mp.begin(); it != mp.end(); it++){
            v.push_back(*it);
        }
        sort(v.begin(), v.end(), cmp);
        
        vector<int> ans;
        int n = v[0].second;
        for(int i = 0; i < v.size(); i++){
            if(v[i].second < n) break;
            ans.push_back(v[i].first);
        }
        return ans;

    }
};