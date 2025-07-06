#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int row, int col, vector <string> &board, int n){
    int row_cpy = row, col_cpy = col;
    //check for upper diagonal
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
        row --;
        col --;
    }

    row = row_cpy;
    col = col_cpy;
    //check for current row
    while(col>=0){
        if(board[row][col]=='Q') return false;
        col --;
    }

    row = row_cpy;
    col = col_cpy;
    //check for lower diagonal
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
        row ++;
        col --;
    }

    return true;
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }

    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            board[row][col] = 'Q';
            solve(col+1, board, ans, n);
            board[row][col] = '.';
        }
    }
}

vector <vector<string>> N_Queens(int n){
    vector <vector<string>> ans;
    string s(n, '.');
    vector <string> board(n, s);
    solve(0, board, ans, n);
    return ans;
}

int main(){
    int n = 4;
    vector <vector<string>> ans = N_Queens(n);
    for(vector<string> board : ans){
       for(string str : board){
        for(char c : str){
            cout<<c<<" ";
        }
        cout<<endl;
       }
       cout<<endl; 
    }
    cout<<endl;
    return 0;
}