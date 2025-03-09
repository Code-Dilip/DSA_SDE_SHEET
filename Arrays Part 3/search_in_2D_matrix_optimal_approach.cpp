#include<iostream>
#include<vector>
using namespace std;

bool search_in_matrix(vector<vector<int>> mat,int target){
    int n = mat.size();
    int m = mat[0].size();
    
    int low = 0;
    int high = n*m-1;
    while(low < high){
        int mid = (low+high)/2;
        int row = mid/m;
        int col = mid%m;
        if(mat[row][col]==target){
            return true;
        }
        else if(mat[row][col] > target){
            high = mid-1;
        }
        else{
            low = mid+1;
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