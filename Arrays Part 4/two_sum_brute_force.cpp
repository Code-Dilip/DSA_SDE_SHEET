#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> two_sum(vector <int> nums,int target){
    int n = nums.size();
    vector <int> ans(2,-1);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((nums[i]+nums[j])==target){
                ans[0] = i;
                ans[1] = j;
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
    }
    return ans;
}

int main(){
    vector <int> nums = {2,5,6,8,11};
    int target = 14;
    vector <int> ans = two_sum(nums,target);

    for(int idx : ans){
        cout<<idx<<" ";
    }
    cout<<endl;
    return 0;
}