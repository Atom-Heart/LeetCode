class Solution {
public:
    int i;
    bool isValidSerialization(string preorder) {
        vector<string> res = split(preorder);
        i = 0;
        return buildTree(res) && i == res.size();
    }
    bool buildTree(vector<string>& nums){
        if(i == nums.size()) return false;

        if(nums[i++] == "#"){
            return true;
        }
        return buildTree(nums) && buildTree(nums);
    }


    vector<string> split(string data){
        vector<string> res;
        int last_pos = -1;
        for(int i = 0; i < data.size(); i++){
            if(data[i] == ','){
                ++last_pos;
                res.push_back(data.substr(last_pos, i - last_pos));
                last_pos = i;
            }
            /*这一段很重要，否则会漏掉最后一个逗号后面的内容*/
            if(i == data.size() - 1){
                ++last_pos;
                res.push_back(data.substr(last_pos, i - last_pos + 1));
            }
        }
        return res;
    }
};