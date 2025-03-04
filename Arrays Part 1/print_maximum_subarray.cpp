#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void print_max_subarray(vector <int> nums){
    int n = nums.size();
    int curr_sum = 0;
    int max_sum = INT_MIN;
    int start,end;
    for(int i=0;i<n;i++){
        if(curr_sum == 0){
            start = i;
        }
        curr_sum += nums[i];
        if(curr_sum > max_sum){
            end = i;
            max_sum = curr_sum;
        }
        if(curr_sum<0){
            curr_sum = 0;
        }
    }
    cout<<"maximum subarray sum: ";
    cout<<max_sum<<endl;
    cout<<"maximum subarray: ";
    for(int i=start;i<=end;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector <int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    print_max_subarray(nums);
    return 0;
}