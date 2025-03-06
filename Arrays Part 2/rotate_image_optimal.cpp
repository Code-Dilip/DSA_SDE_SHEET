#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate_matrix(vector<vector<int>> &mat){
    int n = mat.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    for(int i=0;i<n;i++){
        reverse(mat[i].begin(),mat[i].end());
    }
}

int main(){
    vector<vector<int>> mat = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    rotate_matrix(mat);
    for(vector<int> row : mat){
        for(int val : row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}