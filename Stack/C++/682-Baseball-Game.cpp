class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> ans;
        for(auto op : ops){
            int n = ans.size();
            if(op == "+"){
                ans.push_back(ans[n - 1] + ans[n - 2]);
            }
            else if(op == "D"){
                ans.push_back(ans[n - 1] * 2);
            }
            else if(op == "C"){
                ans.pop_back();
            }
            else{
                ans.push_back(stoi(op));
            }
        }
        int sum = 0;
        for(int num : ans){
            sum += num;
        }
        return sum;
    }
};