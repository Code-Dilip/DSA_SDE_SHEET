#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> majority_element(vector <int> nums){
    int n = nums.size();
    int min = (n/3)+1;

    int cnt1 = 0, cnt2 = 0;
    int ele1, ele2;

    for(int i=0;i<n;i++){
        if(cnt1==0 && ele2!=nums[i]){
            ele1 = nums[i];
            cnt1 ++;
        }
        else if(cnt2==0 && ele1!=nums[i]){
            ele2 = nums[i];
            cnt2 ++;
        }
        else if(ele1 == nums[i]){
            cnt1 ++;
        }
        else if(ele2 == nums[i]){
            cnt2 ++;
        }
        else{
            cnt1 --;
            cnt2 --;
        }
    }

    cnt1 = cnt2 = 0;
    vector <int> ls;
    for(int i=0;i<n;i++){
        if(ele1 == nums[i]){
            cnt1 ++;
            if(cnt1 == min){
                ls.push_back(ele1);
            }
        }
        if(ele2 == nums[i]){
            cnt2 ++;
            if(cnt2 == min){
                ls.push_back(ele2);
            }
        }
    }

    sort(ls.begin(),ls.end());
    return ls;
}

int main(){
    vector <int> nums = {3,2,3};
    vector <int> soln = majority_element(nums);

    for(int val : soln){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}