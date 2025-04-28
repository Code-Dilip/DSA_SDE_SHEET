#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> combinations_sum_1(vector <int> nums, int target){
    int n = nums.size();
    if(n==0){
        return {{}};
    }

    vector <vector<int>> ans;

    for(int i=0;i<n;i++){
        vector <int> comb;
        int curr_sum = 0;
        int target_cpy = target;
        int j = i;
        while(j<n ){
            if(curr_sum==target){
                ans.push_back(comb);
                break;
            }
            if(nums[j]<=target_cpy){
                target_cpy -= nums[j];
                curr_sum += nums[j];
                comb.push_back(nums[j]);
            }
            else{
                j ++;
            }
        }
    }

    return ans;
}

int main(){

    vector <int> nums = {2,3,6,7};
    int target = 7;
    
    vector<vector<int>> ans = combinations_sum_1(nums, target);

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