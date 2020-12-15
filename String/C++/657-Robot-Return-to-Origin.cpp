class Solution {
public:
    bool judgeCircle(string moves) {
        int Steps1 = 0;//y轴方向
        int Steps2 = 0;//x轴方向
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'U') Steps1--;
            else if(moves[i] == 'D') Steps1++;
            else if(moves[i] == 'L') Steps2--;
            else Steps2++;
        }
        return Steps1 == 0 && Steps2 == 0;

    }
};