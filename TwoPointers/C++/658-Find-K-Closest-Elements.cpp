class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size() - k;
        int left = 0, right = arr.size() - 1;
        while(n--){
            if(x - arr[left] > arr[right] - x){
                left++;
            }
            else if(x - arr[left] > arr[right] - x){
                right--;
            }
            else{
                right--;
            }
        }
        vector<int> ans;
        while(left <= right){
            ans.push_back(arr[left]);
            left++;
        }
        return ans;
    }
};