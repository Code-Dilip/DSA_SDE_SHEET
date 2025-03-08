#include<iostream>
#include<vector>
using namespace std;

void merge_sorted_arrays(vector <int> &arr1, int n, vector <int> &arr2, int m){
    vector <int> arr3(n+m,0);
    int left = 0;
    int right = 0;
    int idx = 0;
    while(left<n && right<m){
        if(arr1[left] <= arr2[right]){
            arr3[idx] = arr1[left];
            left ++;
            idx ++;
        }
        else{
            arr3[idx] = arr2[right];
            right ++;
            idx ++;
        }
    }
    while(left<n){
        arr3[idx] = arr1[left];
        left ++;
        idx ++;
    }
    while(right<m){
        arr3[idx] = arr2[right];
        right ++;
        idx ++;
    }
    for(idx=0;idx<(n+m);idx++){
        if(idx<n){
            arr1[idx] = arr3[idx];
        }
        else{
            arr2[idx-n] = arr3[idx];
        }
    }
}

int main(){
    vector <int> arr1 = {1,2,3,0,0,0};
    int n = 3;
    vector <int> arr2 = {2,5,6};
    int m = 3;
    merge_sorted_arrays(arr1,3,arr2,3);

    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    for(int i=0;i<m;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    return 0;
}