#include<iostream>
#include<vector>
using namespace std;

void helper_func(vector <int> &arr, int idx, vector <vector<int>> &ans){
    if(idx==arr.size()){
        ans.push_back(arr);
        return ;
    }
    for(int i=idx;i<arr.size();i++){
        swap(arr[idx], arr[i]);
        helper_func(arr, idx+1, ans);
        swap(arr[idx], arr[i]);
    }
}

vector <vector<int>> get_all_permutations(vector <int> arr){
    vector<vector<int>> permutations ;
    if(arr.size()==0) return permutations;
    helper_func(arr,0,permutations);
    return permutations;
}


int main(){
    vector <int> arr = {1,2,3};
    vector <vector<int>> permutations = get_all_permutations(arr);
    for(vector <int> permutation : permutations){
        cout<<"[";
        for(auto ele : permutation){
            cout<<ele<<" ";
        }
        cout<<"] ";
    }
    cout<<endl;
    return 0;
}