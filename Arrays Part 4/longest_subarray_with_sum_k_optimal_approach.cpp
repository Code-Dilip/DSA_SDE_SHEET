#include<iostream>
#include<vector>
using namespace std;

int longest_subarray_with_sum_k(vector <int> nums, int k){
    int n = nums.size();
    if(n==0) return 0;

    int left = 0, right = 0;
    long long sum = nums[0];
    int max_length = 0;

    while(right<n){
        while(left<=right && sum>k){
            sum = sum - nums[left];
            left ++;
        }
        if(sum==k){
            max_length = max(max_length, right-left+1);
        }
        right ++;
        if(right < n){
            sum += nums[right];
        }
    }
    return max_length ;
}

int main(){
    vector <int> nums = {15, -2, 2, -8, 1, 7, 10, 23};
    cout<<longest_subarray_with_sum_k(nums,0)<<endl;
    return 0;
}