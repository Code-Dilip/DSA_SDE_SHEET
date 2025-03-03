#include<iostream>
#include<vector>
using namespace std;

int n_c_r(int n, int r){
    long long int res = 1;
    for(int i=0;i<r;i++){
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}

void print_pascal_triangle(int n){
    for(int r=1;r<=n;r++){
        for(int c=1;c<=r;c++){
            cout<<n_c_r(r-1,c-1)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int n = 6;
    print_pascal_triangle(6);
    return 0;
}