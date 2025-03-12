#include<iostream>
#include<vector>
using namespace std;

int merge(vector <int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid+1; 
    
    int temp_cnt = 0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left ++;
        }
        else{
            temp_cnt += mid-left+1;
            temp.push_back(arr[right]);
            right ++;
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
        left ++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right ++;
    }
    
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }

    return temp_cnt;
}

int merge_sort(vector <int> &arr,int low,int high){
    if(low<high){
        int cnt = 0;
        int mid = low +((high-low)/2);

        cnt += merge_sort(arr,low,mid);
        cnt += merge_sort(arr,mid+1,high);

        cnt += merge(arr,low,mid,high);
        
        return cnt;
    }
    return 0;
}

int main(){
    vector <int> arr = {2,5,1,3,4};
    cout<<merge_sort(arr,0,arr.size()-1)<<endl;
    for(int val : arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}