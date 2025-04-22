#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct data{
    int start ;
    int end ;
    int pos;
};

bool comp(struct data val1, struct data val2){
    return val1.end < val2.end;
}

int n_meetings_in_a_room(vector <int> start_time, vector <int> end_time){
    int n = start_time.size();
    if(n==0){
        return 0;
    }

    struct data arr[n];

    for(int i=0;i<n;i++){
        arr[i].start = start_time[i];
        arr[i].end = end_time[i];
        arr[i].pos = i+1;
    }

    sort(arr, arr+n, comp);

    int free_time = arr[0].end;
    int cnt = 1;
    
    for(int i=1;i<n;i++){
        if(arr[i].start > free_time){
            cnt ++;
            free_time = arr[i].end;
        }
    }

    return cnt;
}

int main(){
    vector <int> start_time = {0,3,1,5,5,8};
    vector <int> end_time = {5,4,2,9,7,9};

    cout<<n_meetings_in_a_room(start_time, end_time)<<endl;
    return 0;
}