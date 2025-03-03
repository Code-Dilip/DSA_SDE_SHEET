#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void next_permutation(vector <int> &nums){
        int idx = -1;
        int n = nums.size();
        for(int i=n-2;i>=0;i--){  // Find the dip
            if(nums[i]<nums[i+1]){
                idx = i;
                break;
            }
        }
        if(idx==-1){  // If the last possible combination is given then return the first combination
            reverse(nums.begin(),nums.end());
            return ;
        }
        for(int i=n-1;i>idx;i--){ // find the first greater element, which is greater than nums[idx]
            if(nums[i]>nums[idx]){
                swap(nums[i],nums[idx]);
                break;
            }
        }

        reverse(nums.begin()+(idx+1),nums.end());// reverse the rest of the array as it's in descending order;
        return;
}

int main(){
    vector <int> nums = {1,2,3};
    next_permutation(nums);
    for(int val: nums){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}