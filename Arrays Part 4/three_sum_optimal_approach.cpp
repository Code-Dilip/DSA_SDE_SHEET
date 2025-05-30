#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector <vector<int>> three_sum(vector <int> nums, int target){
    vector <vector<int>> ans;
    sort(nums.begin(),nums.end());
    int n = nums.size();

    for(int i=0;i<n;i++){
        if(i>0 && nums[i]==nums[i-1]){
            continue;
        }
        int j = i+1;
        int k = n-1;
        while (j<k)
        {
            int sum = nums[i]+nums[j]+nums[k];
            if(sum < target){
                j ++;
            }
            else if(sum > target){
                k --;
            }
            else{
                vector <int> temp = {nums[i],nums[j],nums[k]};
                sort(temp.begin(), temp.end());
                ans.push_back(temp);
                j ++;
                k --;
                while (j<k && nums[j]==nums[j-1])
                {
                    j ++;
                }
                while (j<k && nums[k]==nums[k+1])
                {
                    k --;
                }
            }
        }
    }
    return ans;
}

int main(){
    vector <int> nums = {-1,0,1,2,-1,-4};
    int target = 0;

    vector <vector<int>> ans = three_sum(nums,target);
    for( vector<int> unique_triplet : ans){
        cout<<"{ ";
        for(int val : unique_triplet){
            cout<<val<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;
    return 0;
}