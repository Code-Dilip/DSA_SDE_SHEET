#include<iostream>
#include<vector>
using namespace std;

int count_unique_paths(int n,int m){
    int res = 1;
    int N = (n+m-2);
    int r = m-1;

    for(int i=0;i<r;i++){
        res *= (N-i);
        res /= (i+1);
    }
    return res;
}

int main(){
    int n = 3, m = 7;
    cout<<count_unique_paths(n,m)<<endl;
    return 0;
}