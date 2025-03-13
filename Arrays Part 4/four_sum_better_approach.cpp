#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector <vector<int>> four_sum(vector <int> nums,int target){
    set <vector<int>> st;
    int n = nums.size();

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set <int> hash_set;
            for(int k=j+1;k<n;k++){
                int fourth = target - (nums[i]+nums[j]+nums[k]);
                if(hash_set.find(fourth) != hash_set.end()){
                    vector <int> temp = {nums[i],nums[j],nums[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hash_set.insert(nums[k]);
            }
        }
    }

    vector <vector<int>> ans(st.begin(),st.end());
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