#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char c){
    for(int i=0;i<9;i++){
        //check horizontally
        if(board[row][i]==c) return false;
        //check vertically
        if(board[i][col]==c) return false;
        //check wihtin grid
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
    }
    return true;
}

bool helper_func(vector<vector<char>> &board){
    if(board.size()==0) return false;
    for(int row=0;row<9;row++){
        for(int col=0;col<9;col++){
            if(board[row][col]=='.'){
                for(char c='1'; c<='9'; c++){
                    if(isValid(board, row, col, c)){
                        board[row][col] = c;
                        if(helper_func(board)==true) return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void sudoku_solver(vector<vector<char>> &board){
    helper_func(board);
}

int main(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    } ;

    sudoku_solver(board);

    for(vector<char> row: board){
        for(char cell: row){
            cout<<cell<<" ";
        }
        cout<<endl;
    }
    return 0;
}