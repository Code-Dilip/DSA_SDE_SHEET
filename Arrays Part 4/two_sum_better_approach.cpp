#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

vector <int> two_sum(vector <int> nums, int target){
    map <int,int> mp;
    int n = nums.size();

    for(int i=0;i<n;i++){
        int a = nums[i];
        int b = target - a; // a + b = target
        if(mp.find(b) != mp.end()){
            if(mp[b]<i){
                return {mp[b],i};
            }
            return {i,mp[b]};
        }
        mp[a] = i;
    }
    return {-1,-1};
}

int main(){
    vector <int> nums = {2,6,5,8,11};
    int target = 14;

    vector <int> ans = two_sum(nums,target);
    for(int idx : ans){
        cout<<idx<<" ";
    }
    cout<<endl;
    return 0;
}