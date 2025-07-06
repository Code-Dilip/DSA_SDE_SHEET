#include<iostream>
#include<vector>
using namespace std;

void helper_func(int i, int j,int n, int m,vector<vector<int>> maze, vector<vector<int>> &vis, vector<string> &ans, string path){
    if(i==n-1 && j==m-1){
        ans.push_back(path);
        return ;
    }
    //move Down
    if((i+1)<n && !vis[i+1][j] && maze[i+1][j]){
        vis[i+1][j]=1;
        helper_func(i+1, j, n, m, maze, vis, ans, path+'D');
        vis[i+1][j]=0;
    }

    //move Left
    if((j-1)>=0 && !vis[i][j-1] && maze[i][j-1]){
        vis[i][j-1]=1;
        helper_func(i, j-1, n, m, maze, vis, ans, path+'L');
        vis[i][j-1]=0;
    }

    //move Right
    if((j+1)<n && !vis[i][j+1] && maze[i][j+1]){
        vis[i][j+1]=1;
        helper_func(i, j+1, n, m, maze, vis, ans, path+'R');
        vis[i][j+1]=0;
    }

    //move Up
    if((i-1)>=0 && !vis[i-1][j] && maze[i-1][j]){
        vis[i-1][j]=1;
        helper_func(i-1, j, n, m, maze, vis, ans, path+'U');
        vis[i-1][j]=0;
    }
}

vector<string> solve_maze(vector<vector<int>> maze){
    int m = maze.size();
    int n = maze[0].size();
    vector<string> ans = {};
    if(m==0) return ans;
    vector<int> vis_row(n, 0);
    vector<vector<int>> vis(m, vis_row);
    string path = "";
    helper_func(0, 0, n, m, maze, vis, ans, path);
    return ans;
}

int main(){
    vector<vector<int>> maze = {{1,0,0,0}, {1,1,0,1}, {1,1,0,0}, {0,1,1,1}};
    vector<string> ans = solve_maze(maze);
    for(string path : ans){
        cout<<path<<" ";
    }
    cout<<endl;
    return 0;
}