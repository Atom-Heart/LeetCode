class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int index = 1;
        for(int i = citations.size() - 1; i >= 0; i--){
            if(index > citations[i]){
                break;
            }
            index++;
        }
        return index - 1;

    }
};