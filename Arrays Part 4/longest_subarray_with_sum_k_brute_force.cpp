#include<iostream>
#include<vector>
using namespace std;


int longest_subarray_with_sum_k(vector <int> nums,int k){
    int n = nums.size();
    int sum = 0;
    int length = 0;

    for(int i=0,j;i<n;i++){
        sum = 0;
        for( j=i;j<n;j++){
            sum += nums[j];
            if(sum == k){
                length = max(length, j-i+1);
            }
        }
    }

    return length;
}

int main(){
    vector <int> nums = {1, 0, -4, 3, 1, 0};
    cout<<longest_subarray_with_sum_k(nums,0)<<endl;
    return 0;
}