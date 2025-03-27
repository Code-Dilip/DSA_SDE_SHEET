#include<iostream>
#include<vector>
#include<map>
using namespace std;

int count_subarrays_with_sum_k(vector <int> nums, int k){
    int n = nums.size();
    map<int,int> mp;
    int xor_sum = 0;
    mp[xor_sum] ++;
    int cnt = 0;
    
    for(int i=0;i<n;i++){
        xor_sum = xor_sum^nums[i];
        int x = xor_sum ^ k;
        cnt += mp[x];
        mp[xor_sum] ++;
    }

    return cnt;
}

int main(){
    vector <int> nums = {4, 2, 2, 6, 4};
    cout<<count_subarrays_with_sum_k(nums,6)<<endl;
    return 0;
    return 0;
}