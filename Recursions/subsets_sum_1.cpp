#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void helper_func(vector <int> arr, int n, int idx, int curr_sum, vector <int> &sums){
    if(idx == n){
        sums.push_back(curr_sum);
        return ;
    }
    helper_func(arr, n, idx+1, curr_sum+arr[idx], sums); //choose element at particular index
    helper_func(arr, n, idx+1, curr_sum, sums); //Don't choose element at particular index
}

vector <int> subset_sum(vector <int> arr){
    if(arr.size()==0) return {};
    int n = arr.size();
    vector <int> sums;
    helper_func(arr, n, 0, 0, sums);
    sort(sums.begin(), sums.end());
    return sums;
}

int main(){
    vector <int> arr = {2,3};
    vector <int> subsets_sum = subset_sum(arr);
    for(auto it : subsets_sum){
        cout<<it<<" ";
    }
    cout<<endl;
}