#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int max_subarray_sum(vector <int> &nums){
    int n = nums.size();
    int max_sum = INT_MIN;
    for(int st=0;st<n;st++){
        for(int end=0;end<n;end++){
            int curr_sum = 0;
            for(int i=st;i<=end;i++){
                curr_sum += nums[i];
            }
            max_sum = max(max_sum,curr_sum);
        }
    }
    return max_sum;
}

int main(){
    vector <int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<max_subarray_sum(nums)<<endl;
    return 0;
}