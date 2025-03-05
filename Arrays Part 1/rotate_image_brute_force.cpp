#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotate_matrix(vector <vector <int>> mat){
    // n*n matrix
   int n = mat.size();
   vector<vector<int>> temp_mat(n,vector<int>(n,0));
   for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        temp_mat[j][(n-1)-i] = mat[i][j];
    }
   }
   return temp_mat;
}

int main(){
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    mat = rotate_matrix(mat);
    for(vector <int> row : mat){
        for(int val: row){
            cout<<val<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}