#include<iostream>
#include<vector>
using namespace std;

int find_duplicates(vector <int> nums){
    vector <int> temp(nums.size(),0);
    int i;
    for(i=0;i<nums.size();i++){
        if(temp[nums[i]]==0){
            temp[nums[i]]++;
        }
        else{
            break;
        }
    }
    return nums[i];
}
int main(){
    vector<int> nums = {1,3,4,2,2};
    cout<<find_duplicates(nums)<<endl;
    return 0;
}