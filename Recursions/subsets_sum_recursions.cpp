#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subsets_sum(vector <int> &nums, vector <int> &sum_arr, int idx, int sum){
    if(idx == nums.size()){
        sum_arr.push_back(sum);
        return ;
    }

    subsets_sum(nums, sum_arr, idx+1, sum+nums[idx]); // pick the element which is at index idx
    subsets_sum(nums, sum_arr, idx+1, sum); //Don't pick the element which is at index idx
}

int main(){
    vector <int> nums = {5,2,1};
    vector <int> sum_arr ;
    
    subsets_sum(nums, sum_arr, 0, 0);
    sort(sum_arr.begin(), sum_arr.end());

    for(int val : sum_arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}