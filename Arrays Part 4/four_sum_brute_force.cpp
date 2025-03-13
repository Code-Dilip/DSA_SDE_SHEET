#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector <vector<int>> four_sum(vector <int> nums, int target){
    int n = nums.size();
    set <vector<int>> st;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    if((nums[i]+nums[j]+nums[k]+nums[l]) == target){
                        vector <int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

int main(){
    vector <int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector <vector<int>> quads = four_sum(nums,target);

    for(vector <int> quad : quads){
        cout<<"{ ";
        for(int val : quad){
            cout<<val<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;
    return 0;
}