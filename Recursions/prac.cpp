#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void non_duplicates_subsets(vector <int> nums, vector <vector<int>> &ans, vector <int> &ds, int idx){
    ans.push_back(ds);
    
    for(int i=idx; i<nums.size(); i++){
        if(i!=idx && nums[i]==nums[i-1]) continue;
        ds.push_back(nums[i]);
        non_duplicates_subsets(nums, ans, ds, i+1);
        ds.pop_back();
    }
}

int main(){
    vector <int> nums = {1,2,2};
    vector <int> ds;
    vector <vector<int>> ans;

    sort(nums.begin(), nums.end());

    non_duplicates_subsets(nums, ans, ds, 0);
    
    for(vector <int> subset : ans){
        cout<<"{";
        for(int val : subset){
            cout<<val<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;
    return 0;
}