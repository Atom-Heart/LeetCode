/*自底至上*/
class Solution {
public:
    string countAndSay(int n) {
        int step = 1;
        string route = "1";
        while(n != step){
            int count = 1;
            string cur;
            for(int i = 0; i < route.size(); i++){
                if(i == route.size() - 1){
                    if(count == 1){
                        cur += to_string(1);
                    }
                    else{
                        cur += to_string(count);
                    }
                     cur += route[i];
                }
                else if(route[i] == route[i + 1]){
                    count++;
                }
                else{
                    cur += to_string(count);
                    cur += route[i];
                    count = 1;
                }
            }
            route = cur;
            step++;
        }
        return route;
    }
};