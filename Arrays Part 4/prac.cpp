#include<iostream>
#include<vector>
#include<map>
using namespace std;

int count_subarray_with_xorsum_k(vector <int> nums, int k){
    int n = nums.size();
    if(n==0) return n;
    int cnt = 0;
    int xor_sum = 0;
    map <int,int> mp;
    mp[xor_sum] ++;

    for(int i=0;i<n;i++){
        xor_sum ^= nums[i];
        int x = xor_sum ^ k;
        cnt += mp[x];
        mp[xor_sum] ++;
    }

    return cnt;
}

int main(){
    vector <int> nums = {5, 6, 7, 8, 9};
    cout<<count_subarray_with_xorsum_k(nums,5)<<endl;
    return 0;
}