#include<iostream>
#include<vector>
using namespace std;

vector <int> repeating_and_missing_element(vector<int> nums){
    int n = nums.size();
    vector<int> soln(2,-1);

    for(int i=1;i<=n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(i==nums[j]){
                cnt ++;
            }
        }
        if(cnt==2){
            soln[0] = i;
        }
        else if(cnt==0){
            soln[1] = i;
        }
        if(soln[0]!=-1 && soln[1]!=-1){
            break;
        }
    }
    return soln;
}

int main(){
    vector<int> nums = {1, 1};
    vector <int> soln = repeating_and_missing_element(nums);
    for(int val : soln){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}