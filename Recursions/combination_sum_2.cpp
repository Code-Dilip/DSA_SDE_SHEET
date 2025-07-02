#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void helper_func(vector <int> arr, int n, int target, int idx, vector<int> &ds, vector<vector<int>> &ans){
    if(target==0){
        ans.push_back(ds);
        return ;
    }
    for(int i=idx;i<n;i++){
        if(i>idx && arr[i]==arr[i-1]) continue;
        if(arr[i] > target) break;
        ds.push_back(arr[i]);
        helper_func(arr, n, target-arr[i], i+1, ds, ans);
        ds.pop_back();
    }
}

vector <vector<int>> combinations_sum_2(vector <int> arr, int target){
    int n = arr.size();
    if(n==0) return {{}};
    sort(arr.begin(), arr.end());
    vector <vector<int>> ans;
    vector<int> ds;
    helper_func(arr, n, target, 0, ds, ans);
    return ans;
}

int main(){
    vector <int> arr = {1,1,1,2,2};
    int target = 4;
    vector <vector<int>> ans;
    ans = combinations_sum_2(arr, target);
    
    for(vector <int> combination : ans){
        cout<<"[";
        for(int ele : combination){
            cout<<ele<<" ";
        }
        cout<<"] ";
    }
    cout<<endl;
    return 0;
}