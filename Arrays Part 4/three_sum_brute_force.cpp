#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector <vector<int>> three_sum(vector <int> nums,int target){
    set <vector<int>> st;
    int n = nums.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=i+1;j<n;j++){
                if((nums[i]+nums[j]+nums[k])==target){
                    vector <int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector <vector<int>> ans{st.begin(),st.end()};
    return ans;
}

int main(){
    vector <int> nums = {-1,0,1,2,-1,-4};
    int target = 0;
    vector <vector <int>> ans = three_sum(nums,target);

    for(vector <int> unique_triplet : ans){
        cout<<"{";
        for(int val : unique_triplet){
            cout<<val<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;
    return 0;
}