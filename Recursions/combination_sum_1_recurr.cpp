#include<iostream>
#include<vector>
using namespace std;

void helper_func(vector <int> arr, int n, int target, int idx, vector <int> &ds, vector <vector<int>> &ans){
    if(idx==n){
        if(target==0){
            ans.push_back(ds);
        }
        return ;
    }
    // pick up a element
    if(arr[idx]<=target){
        ds.push_back(arr[idx]);
        helper_func(arr, n, target-arr[idx], idx, ds, ans);
        ds.pop_back();
    }
    // Don't pick the current element, pick up the next element
    helper_func(arr, n, target, idx+1, ds, ans);
}

vector <vector<int>> combinations_sum(vector <int> arr, int target){
    int n = arr.size();
    if(n==0) return {{}};
    vector <vector<int>> ans;
    vector <int> ds;
    helper_func(arr, n, target, 0, ds, ans);
    return ans;
}

int main(){
    vector <int> arr = {2,3,6,7};
    int target = 7;

    vector <vector<int>> ans;
    ans = combinations_sum(arr, target);

    for(vector <int> combination : ans){
        cout<<"[";
        for(int ele : combination){
            cout<<ele<<" ";
        }
        cout<<"]";
    }
    cout<<endl;
    return 0;
}