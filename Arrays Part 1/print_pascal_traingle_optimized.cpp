#include<iostream>
#include<vector>
using namespace std;

void print_row(int n){
    long long int pas_row = 1;
    cout<<pas_row<<" ";
    for(int c=1;c<n;c++){
        pas_row *= (n-c);
        pas_row /= c;
        cout<<pas_row<<" ";
    }
    cout<<endl;
}

void print_pascal_triangle(int n){
    for(int i=1;i<=n;i++){
        print_row(i);
    }
    cout<<endl;
}

int main(){
    int n = 6;
    print_pascal_triangle(6);
    return 0;
}