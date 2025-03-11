#include<iostream>
#include<vector>
using namespace std;

int count_possible_paths(int i, int j, int n, int m){
    if(i==n-1 && j==m-1){
        return 1;
    }
    if(i>=n || j>=m){
        return 0;
    }
    return count_possible_paths(i+1,j,n,m) + count_possible_paths(i,j+1,n,m);
}

int main(){
    int n = 7;
    int m = 3;
    cout<<count_possible_paths(0,0,n,m)<<endl;
    return 0;
}