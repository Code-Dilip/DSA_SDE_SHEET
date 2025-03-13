#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector <int> two_sum(vector <int> nums, int target){
    map <int,int> mp;
    int n = nums.size();
    for(int i=0;i<n;i++){
        mp[nums[i]] = i;
    }

    sort(nums.begin(),nums.end());
    
    int left = 0,right = n-1;
    while(left<right){
        if((nums[left]+nums[right])==target){
            if(mp[nums[left]] < mp[nums[right]]){
                return {mp[nums[left]],mp[nums[right]]};
            }
            return {mp[nums[right]],mp[nums[left]]};
        }
        else if((nums[left]+nums[right])<target){
            left ++;
        }
        else{
            right --;
        }
    }
    return {-1,-1};
}

int main(){
    vector <int> nums = {2,5,6,7,8,11};
    int target = 14;
    vector <int> ans = two_sum(nums,target);
    for(int idx : ans){
        cout<<idx<<" ";
    }
    cout<<endl;
    return 0;
}