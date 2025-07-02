#include<iostream>
#include<vector>
using namespace std;

void helper_func(vector<int> arr, int n, int idx, vector <int> &ds, vector<vector<int>> &ans){
    ans.push_back(ds);
    for(int i=idx;i<n;i++){
        if(i!=idx && arr[i]==arr[i-1]) continue;
        ds.push_back(arr[i]);
        helper_func(arr, n, idx+1, ds, ans);
        ds.pop_back();
    }
}

vector <vector<int>> uniqueSubsets(vector <int> arr){
    int n = arr.size();
    if(n==0) return {{}};
    vector <vector<int>> ans;
    vector<int> ds;
    helper_func(arr, n, 0, ds, ans);
    return ans;
}

int main(){
    vector <int> arr = {1, 2, 2};
    vector <vector<int>> unique_subsets = uniqueSubsets(arr);

    for(vector <int> unique_subset : unique_subsets){
        cout<<"[";
        for(int ele : unique_subset){
            cout<<ele<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
    return 0;
}