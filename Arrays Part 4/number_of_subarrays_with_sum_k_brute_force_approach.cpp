#include<iostream>
#include<vector>
using namespace std;

int count_subarrays_with_sum_k(vector <int> nums, int k){
    int cnt = 0;
    int n = nums.size();
    
    for(int i=0;i<n;i++){
        int xor_sum = 0;
        for(int j=i;j<n;j++){
            xor_sum = xor_sum ^ nums[j];
            if(xor_sum == k){
                cnt ++;
            }
        }
    }

    return cnt;
}

int main(){
    vector <int> nums = {4, 2, 2, 6, 4};
    cout<<count_subarrays_with_sum_k(nums,6)<<endl;
    return 0;
}