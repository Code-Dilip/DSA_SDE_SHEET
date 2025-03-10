#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> majority_element(vector <int> nums){
    int n = nums.size();
    int min = (n/3)+1;
    int cnt = 0;
    vector <int> ls;

    for(int i=0;i<n;i++){
        if(ls.size()==0 || ls[0]!=nums[i]){
            cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    cnt ++;
                }
            }
            if(cnt >= min){
                ls.push_back(nums[i]);
            }
            if(ls.size()==2){
                break;
            }
        }
    }
    sort(ls.begin(),ls.end());
    return ls;
}

int main(){
    vector <int> nums = {1,2};
    vector <int> soln = majority_element(nums);

    for(int val : soln){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}