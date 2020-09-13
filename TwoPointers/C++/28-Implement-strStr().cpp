/*超时，要用kmp*/
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]){
                int index = i;
                int j = 0;
                while(index < haystack.size() && j < needle.size()){
                    if(haystack[index] == needle[j]){
                        if(j == needle.size() - 1){
                            return i;
                        }
                        else{
                            index++;
                            j++;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        return -1;
    }
};