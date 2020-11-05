/*由大到小排序，对比排序前后的字符串，找出第一个不一样的，这两个就是要交换的数*/
/*不用这种方法我做不出来，需要考虑很多细节*/
class Solution {
public:
    int maximumSwap(int num) {
        if(num <= 9) return num;
        
        string s = to_string(num);
        string temp(s);

        sort(temp.begin(), temp.end(), [](char a, char b){return a > b;});

        int tar = -1;//表示第一个不一样的位
        for(int i = 0; i < s.size(); i++){
            if(temp[i] != s[i]){
                tar = i;
                break;
            }
        }
        for(int i = s.size() - 1; i >= tar + 1; i--){
            if(s[i] == temp[tar]){
                swap(s[i], s[tar]);
                break;
            }
        }
        return stoi(s);
    }
};