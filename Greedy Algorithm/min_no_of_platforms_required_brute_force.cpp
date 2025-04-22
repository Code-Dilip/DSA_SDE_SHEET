#include<iostream>
#include<vector>
using namespace std;

int min_no_of_platforms(vector <float> arrival, vector <float> departure){
    int n = arrival.size();
    if(n==0){
        return 0;
    }

    int max_cnt = 0, cnt = 0;

    for(int i=0;i<n;i++){
        int cnt = 1;
        for(int j=i+1;j<n;j++){
            if(arrival[j]>=arrival[i] && arrival[j]<=departure[i]){
                cnt ++;
            }
            max_cnt = max(max_cnt , cnt);
        }
    }

    return max_cnt;
}

int main(){
    
    vector <float> arrival = {9.00, 9.45, 9.55, 11.00, 15.00, 18.00};
    vector <float> departure = {9.20, 12.00, 11.30, 11.50, 19.00, 20.00};

    cout<<min_no_of_platforms(arrival, departure)<<endl;
    return 0;
}