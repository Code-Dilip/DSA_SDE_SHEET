#include<iostream>
#include<vector>
using namespace std;

void sort(vector<int> &nums){
    int n = nums.size();
    int low = 0;
    int mid = 0;
    int hight = n-1;

    while(mid<=hight){
        if(nums[mid]==0){
            swap(nums[low],nums[mid]);
            low ++;
            mid ++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            // when nums[mid]==2
            swap(nums[mid],nums[hight]);
            hight --;
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