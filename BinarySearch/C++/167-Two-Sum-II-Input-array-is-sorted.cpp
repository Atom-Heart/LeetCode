class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size() - 1; i++){
            int left = i + 1, right = numbers.size() - 1;
            while(left < right){
                int mid = (left + right) >> 1;
                if(numbers[i] + numbers[mid] >= target) right = mid;
                else left = mid + 1;
            }
            if(numbers[i] + numbers[left] == target) return {i + 1, left + 1};
        }
        return {};
    }
};