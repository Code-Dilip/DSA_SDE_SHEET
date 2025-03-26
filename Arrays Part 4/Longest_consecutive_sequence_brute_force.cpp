#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int longest_consecutive_sequence(vector <int> arr){
    int n = arr.size();
    int max_length = 1;
    
    for(int i=0;i<n;i++){
        int cnt = 1;
        int x = arr[i];
        while(find(arr.begin(),arr.end(),x+1) != arr.end()){
            cnt ++;
            x ++;
        }
        max_length = max(cnt,max_length);
    }
    return max_length;
}

int main(){
    vector <int> arr = {0,3,7,2,5,8,4,6,0,1};
    cout<<longest_consecutive_sequence(arr)<<endl;
    return 0;
}