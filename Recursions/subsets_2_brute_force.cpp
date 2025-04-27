#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector <vector<int>> non_duplicates_subsets(vector <int> &nums){
    int n = nums.size();
    if(n==0){
        return {};
    }

    set <vector <int>> ans;
    ans.insert({});

    for(int i=0;i<n;i++){
        ans.insert({nums[i]});
        for(int j=i+1;j<n;j++){
            vector <int> subset;
            for(int k=i;k<=j;k++){
                subset.push_back(nums[k]);
            }
            ans.insert(subset);
        }
    }

    vector <vector<int>> res(ans.begin(), ans.end());
    return res;
}

int main(){
    vector <int> nums = {1,2,2};
    vector <vector<int>> res = non_duplicates_subsets(nums);

    for(vector <int> subset : res){
        cout<<"{ ";
        for(int val : subset){
            cout<<val<<" ";
        }
        cout<<"}";
    }
    return 0;
}