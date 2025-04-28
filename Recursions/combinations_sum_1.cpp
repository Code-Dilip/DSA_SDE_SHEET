#include<iostream>
#include<vector>

using namespace std;

void combinations_sum_1(vector <int> nums, vector <int> &ds, vector <vector<int>> &ans, int idx, int target){
    if(idx==nums.size()){
        if(target==0){
            ans.push_back(ds);
        }
        return ;
    }

    //Pick the element
    if(nums[idx]<=target){
        ds.push_back(nums[idx]);
        combinations_sum_1(nums, ds, ans, idx, target-nums[idx]);
        ds.pop_back();
    }

    //Don't Pick the element
    combinations_sum_1(nums, ds, ans, ++idx, target);
}

int main(){

    vector <int> nums = {2,3,6,7};
    vector <vector <int>> ans ;
    vector <int> ds;
    int target = 7;
    
    combinations_sum_1(nums, ds, ans, 0, target);

    for(vector <int> combination : ans){
        cout<<"{";
        for(int val : combination){
            cout<<val<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;
    return 0;
}