#include<iostream>
#include<vector>
using namespace std;

double Pow(int x,int n){
    if(n==0){
        return 1;
    }
    int nn = n;
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
        ans = 1/(long)ans;
    }
    return ans;
}

int main(){
    int x = 2, n = 10;
    cout<<Pow(x,n)<<endl;
    return 0;
}