class Solution {
public:
    int findNthDigit(int n) {
        /*位数：1，2，3····*/
        int digit = 1;
        /*当前位的起始索引：1， 10， 100····*/
        long long start = 1;
        /*当前位所含的下标总数:9, 180,····*/
        long long index_count = 9;
        
        while(index_count < n){
            digit++;
            start *= 10;
            n -= index_count;
            index_count = digit * 9 * start;
        }
        /*这里细节很多，注意边界*/
        long long num = start + (n - 1) / digit;
        string str = to_string(num);
        cout<<str;
        return str[(n - 1) % digit] - '0';
    }
};