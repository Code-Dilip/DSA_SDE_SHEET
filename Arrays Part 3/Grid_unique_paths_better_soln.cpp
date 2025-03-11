// using Dynamic Programming
#include<iostream>
#include<vector>
using namespace std;

int count_unique_paths(int i,int j,int n,int m,vector<vector<int>> &dp){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i>=n || j>=m){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else return dp[i][j]=count_unique_paths(i+1,j,n,m,dp) + count_unique_paths(i,j+1,n,m,dp);
}

int main(){
    int n = 7, m = 3;
    vector <vector<int>> dp(n,vector<int> (m,-1));
    cout<<count_unique_paths(0,0,n,m,dp)<<endl;
    return 0;
}