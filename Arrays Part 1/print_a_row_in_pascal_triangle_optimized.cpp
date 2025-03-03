#include<iostream>
#include<vector>
using namespace std;

void print_row(int n){
    long long int pas_row = 1;
    cout<<pas_row<<" ";
    for(int i=1;i<n;i++){
        pas_row = pas_row * (n-i);
        pas_row = pas_row / i;
        cout<<pas_row<<" ";
    }
    cout<<endl;
}

int main(){
    int n = 6;
    print_row(n);
    return 0;
}