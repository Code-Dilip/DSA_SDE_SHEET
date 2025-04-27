#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector <int> subsets_sum(vector <int> nums){
    int n = nums.size();
    if(n==0){
        return {};
    }

    vector <int> ans;
    ans.push_back(0);
    
    for(int i=0;i<n;i++){
        ans.push_back(nums[i]);
        for(int j=i+1;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += nums[k];
            }
            ans.push_back(sum);
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main(){
    vector <int> nums = {5,2,1};
    vector <int> res = subsets_sum(nums);

    for(int val : res){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}