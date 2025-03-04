#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> &nums){
    int n = nums.size();
    int low=0,mid=0,higth=n-1;
    while(mid<=higth){
        if(nums[mid]==0){
            swap(nums[mid],nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[mid],nums[higth]);
            higth --;
        }
    }
}

int main(){
    vector <int> nums = {2,0,2,1,1,0};
    sort(nums);
    for(int val: nums){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}