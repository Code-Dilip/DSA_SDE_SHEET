#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int longest_consequtive_sequence(vector <int> arr){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int cnt = 1;
    int max_length = 1;
    int last_smallest = INT_MIN;

    for(int i=0;i<n;i++){
        if((arr[i]-1)==last_smallest){
            cnt ++;
            last_smallest = arr[i];
        }
        else {
            cnt = 1;
            last_smallest = arr[i];
        }
        max_length = max(max_length, cnt);
    }
    return max_length;
}

int main(){
    vector <int> arr = {100,4,200,1,3,2};
    cout<<longest_consequtive_sequence(arr)<<endl;
    return 0;
}
