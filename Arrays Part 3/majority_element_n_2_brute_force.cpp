#include<iostream>
#include<vector>
using namespace std;

int majority_ele(vector<int> arr){
    int n = arr.size();
    int min = (n/2)+1;
    
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                cnt ++;
            }
        }
        if(cnt >= min){
            return arr[i];
        }
    }
    return -1;
}

int main(){
    vector <int> arr = {2,2,1,1,1,2,2};
    cout<<majority_ele(arr)<<endl;
    return 0;
}