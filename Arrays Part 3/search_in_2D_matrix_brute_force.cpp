#include<iostream>
#include<vector>
using namespace std;

bool search_in_matrix(vector<vector<int>> mat, int target){
    int n = mat.size();
    int m = mat[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==target){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector <vector<int>> mat = {
        {3,4,7,9},
        {12,13,16,18},
        {20,21,23,29}
    };
    int target = 23;
    cout<<search_in_matrix(mat,target)<<endl;
    return 0;
}