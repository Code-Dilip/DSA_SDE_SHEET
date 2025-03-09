#include<iostream>
#include<vector>
using namespace std;

void swapIfGreater(vector<int>&arr1,vector<int>&arr2,int idx1,int idx2){
    if(arr1[idx1]>=arr2[idx2]){
        swap(arr1[idx1],arr2[idx2]);
    }
}

void merge_2_sorted_arrays(vector<int>&arr1, int n, vector<int>&arr2, int m){
    int len = (n+m);
    int gap = (len/2)+(len%2);
    
    while(gap > 0){
        int left = 0;
        int right = gap;
        while (right < len)
        {   
            // arr1 and arr1
            if(left<n && right<n){
                swapIfGreater(arr1,arr1,left,right);
            }
            // arr2 and arr2
            else if(left>=n && right>=n){
                swapIfGreater(arr2,arr2,left-n,right-n);
            }
            // arr1 and arr2
            else if(left<n && right>=n){
                swapIfGreater(arr1,arr2,left,right-n);
            }
            left ++;
            right ++;
        }
        if(gap==1){
            break;
        }
        gap = (gap/2) + (gap%2);
    }
    for(int i=n;i<arr1.size();i++){
        arr1[i] = arr2[i-n];
    }
}

int main(){
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {0,2,6,8,9};
    int n = arr1.size();
    int m = arr2.size();
    merge_2_sorted_arrays(arr1,n,arr2,m);
    for(int val: arr1){
        cout<<val<<" ";
    }
    for(int val: arr2){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}