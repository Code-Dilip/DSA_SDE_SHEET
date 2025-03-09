#include<iostream>
#include<vector>
using namespace std;

double Pow(int x,int n){
    if(n==0){
        return 1;
    }
    long long int nn = n; //edge case when -n is too small
    if(n<0){
        nn *= -1;
    }
    double ans = 1;
    while(nn>0){
        if(nn%2){
            ans = ans*x;
            nn = nn-1;
        }
        else{
            x = x*x;
            nn = nn/2;
        }
    }
    if(n<0){
        ans = (double)(1.0)/(double)ans; // when x is float
    }
    return ans;
}

int main(){
    int x = 2, n = 10;
    cout<<Pow(x,n)<<endl;
    return 0;
}