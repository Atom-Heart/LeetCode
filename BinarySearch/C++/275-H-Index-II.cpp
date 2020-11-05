class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if(len == 0 || citations[len - 1] == 0){
            return 0;
        }
        int left = 0;
        int right = len - 1;

        while(left < right){
            int mid = left + (right - left) / 2;
            if(len - mid > citations[mid]){
                left = mid + 1;
            }
            else{
                right = mid;
            }
        }
        return len - left;
    }
};