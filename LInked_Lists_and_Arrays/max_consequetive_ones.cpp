#include<iostream>
#include<vector>
using namespace std;

int max_consequetive_ones(vector <int> arr){
    int n = arr.size();
    int cnt = 0, max_cnt = 0;
    
    for(int i=0;i<n;i++){
        if(arr[i]==1){
            cnt ++;
            max_cnt = max(max_cnt, cnt);
        }
        else{
            cnt = 0;
        }
    }
    
    return max_cnt;
}

int main(){
    vector <int> arr = {1,1,0,1,1,1,0,1,1};
    cout<<max_consequetive_ones(arr)<<endl;
    return 0;
}