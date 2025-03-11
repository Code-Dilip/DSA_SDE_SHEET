#include<iostream>
#include<vector>
using namespace std;


int count_reverse_pairs(vector <int> nums){
    int n = nums.size();
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]>2*nums[j]){
                cnt ++;
            }
        }
    }
    return cnt;
}

int main(){
    vector <int> nums = {40,25,19,12,9,6,2};
    cout<<count_reverse_pairs(nums)<<endl;
    return 0;
}