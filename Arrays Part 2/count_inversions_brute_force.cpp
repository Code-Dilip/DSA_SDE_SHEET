#include<iostream>
#include<vector>
using namespace std;

int count_inversions(vector <int> arr){
    int cnt=0;
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                cnt ++;
            }
        }
    }
    return cnt;
}

int main(){
    vector <int> arr = {2,5,1,3,4};
    cout<<count_inversions(arr)<<endl;
    return 0;
}