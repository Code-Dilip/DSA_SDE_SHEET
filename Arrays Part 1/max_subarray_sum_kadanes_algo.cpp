#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int max_subarray_sum(vector <int> nums){
    int n = nums.size();
    int curr_sum = 0;
    int max_sum = 0;
    for(int i=0;i<n;i++){
        curr_sum += nums[i];
        max_sum = max(max_sum,curr_sum);
        if(curr_sum<0){
            curr_sum = 0;
        }
    }
    return max_sum;
}

int main(){
    vector <int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<max_subarray_sum(nums)<<endl;
    return 0;
}