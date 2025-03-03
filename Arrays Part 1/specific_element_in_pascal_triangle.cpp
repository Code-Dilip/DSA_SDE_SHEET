#include<iostream>
#include<vector>
using namespace std;

int n_c_r(int n, int r){
    long long int res = 1;
    for(int i=0;i<r;i++){
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}

int main(){
    int r = 5, c = 3;
    cout<<n_c_r(r-1,c-1)<<endl;
    return 0;
}