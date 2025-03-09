// This Program make use of Linked List Cycle Method
#include<iostream>
#include<vector>
using namespace std;

int find_duplicates(vector<int> nums){
    int fast = nums[0];
    int slow = nums[0];

    do{
        fast = nums[nums[fast]];
        slow = nums[nums[slow]];
    }
    while(fast!=slow);

    fast = nums[0];
    while(slow!=fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main(){
    vector <int> nums = {1,3,4,2,2};
    cout<<find_duplicates(nums)<<endl;
    return 0;
}