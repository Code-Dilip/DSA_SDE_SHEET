#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void unique_combinations_sum(vector <int> nums, vector <vector<int>> &ans, vector <int> &ds, int target, int idx){
    if(target==0){
        ans.push_back(ds);
        return ;
    }

    for(int i=idx;i<nums.size();i++){
        if(i!=idx && nums[i]==nums[i-1]) continue;
        if(nums[i]<=target){
            ds.push_back(nums[i]);
            unique_combinations_sum(nums, ans, ds, target-nums[i], i+1);
            ds.pop_back();
        }
        else{
            break;
        }
    }
}

int main(){
    vector <int> nums = {10, 1, 2, 7, 6, 1, 5};
    vector <int> ds;
    vector <vector<int>> ans;
    int target = 8;

    sort(nums.begin(), nums.end());
    unique_combinations_sum(nums, ans, ds, target, 0);

    for(vector <int> unique_combination : ans){
        cout<<"{";
        for(int val : unique_combination){
            cout<<val<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;
    return 0;
}