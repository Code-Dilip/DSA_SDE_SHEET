#include<iostream>
#include<vector>
#include<map>
using namespace std;


int longest_subarray_with_sum_k(vector <int> nums, int k){
    int n = nums.size();

    int sum = 0;
    int max_length = 1;
    
    map <int,int> prefix_sum_mp;
    
    for(int i=0;i<n;i++){
        sum += nums[i];
        if(sum==k){
            max_length = max(max_length,i+1);
        }
        int rem = sum - k;
        if(prefix_sum_mp.find(rem) != prefix_sum_mp.end()){
            int len = i - prefix_sum_mp[rem] ;
            max_length = max(max_length, len);
        }
        if(prefix_sum_mp.find(sum) == prefix_sum_mp.end()){
            prefix_sum_mp[sum] = i;
        }
    }

    return max_length;
}

int main(){
    vector <int> nums = {15, -2, 2, -8, 1, 7, 10, 23};
    cout<<longest_subarray_with_sum_k(nums,0)<<endl;
    return 0;
    return 0;
}