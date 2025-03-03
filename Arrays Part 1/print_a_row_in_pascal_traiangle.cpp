#include<iostream>
#include<vector>
using namespace std;


int n_c_r(int n, int r){
    long long res = 1;
    for(int i=0;i<r;i++){
        res = res * (n-i);
        res = res / (i+1);
    }
    return res;
}

void print_row(int n){
    for(int c=1;c<=n;c++){
        cout<<n_c_r(n-1,c-1)<<" ";
    }
    cout<<endl;
}

int main(){
    int n = 6;
    print_row(6);
    return 0;
}