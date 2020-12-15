#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>> matrix;
bool isVaild(int row, int col){
    for(int i = 0; i <= row; i++){
        if(matrix[i][col] == 'Q') return false;
    }
    
    for(int i = row - 1, j = col + 1; i >= 0 && j <= matrix[row].size(); i--, j++){
        if(matrix[i][j] == 'Q') return false;
    }
    
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
        if(matrix[i][j] == 'Q') return false;
    }
    return true;
}

void backTracking(int row){
    if(row == matrix.size()){
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                cout<<matrix[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    
    for(int i = 0; i < matrix[row].size(); i++){
        if(isVaild(row, i)){
            matrix[row][i] = 'Q';
            backTracking(row + 1);
            matrix[row][i] = '.';
        }
    }
    
}


int main(){
    int n;
    cin >> n;
    matrix = vector<vector<char>>(n, vector<char>(n, '.'));
    backTracking(0);
    return 0;
}