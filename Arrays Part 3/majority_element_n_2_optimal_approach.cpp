// using moore's voting algorithm
#include<iostream>
#include<vector>
using namespace std;

int majority_element(vector <int> arr){
    int n = arr.size();
    int min = (n/2)+1;

    int cnt = 0;
    int ele;
    
    for(int i=0;i<n;i++){
        if(cnt==0){
            ele = arr[i];
            cnt ++;
        }
        else if(arr[i]==ele){
            cnt ++;
        }
        else{
            cnt --;
        }
    }

    // check whether ele appears more than n/2 times
    cnt = 0;
    for(int i=0;i<n;i++){
        if(ele==arr[i]){
            cnt ++;
        }
        if(cnt == min){
            return ele;
        }
    }
    return -1;
}

int main(){
    vector <int> arr = {2,2,1,1,1,2,2};
    cout<<majority_element(arr)<<endl;
    return 0;
}