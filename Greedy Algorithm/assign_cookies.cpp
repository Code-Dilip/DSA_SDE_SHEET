#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int assign_cookies_to_max_children(vector <int> greed, vector <int> cookies){
    int n = greed.size(), m = cookies.size();
    int r = 0, l = 0;

    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());

    while(l<m && r<n){
        if(greed[r]<=cookies[l]){
            r ++;
        }
        l ++;
    }

    return r;
}

int main(){
    vector <int> greed = {1,2}, cookies = {1,2,3};
    cout<<assign_cookies_to_max_children(greed, cookies)<<endl;
    return 0;
}