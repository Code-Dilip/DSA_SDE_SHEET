#include<iostream>
#include<vector>
using namespace std;

vector <int> repeating_and_missing_element(vector <int> nums){
    vector <int> soln(2,0);
    int n = nums.size();

    long long int s,sn,s2,s2n;
    s = sn = s2 = s2n = 0;
    for(int i=0;i<n;i++){
        s += (long long)(nums[i]);
        sn += (long long)(i+1);
        s2 += (long)nums[i] * (long)nums[i];
        s2n += (long)(i+1) * (long)(i+1);
    }

    long long int val1 = (long long)(s - sn); // (x - y)
    long long int val2 = (long long)(s2 - s2n); // (x*x - y*y)
    val2 = (val2 / val1); // (x + y) = (x*x - y*y) / (x - y)
    long long int x = (val1 + val2) / 2;
    long long int y = (x - val1);

    soln[0] = x;
    soln[1] = y;

    return soln;
}

int main(){
    vector <int> nums = {3,1,2,5,3};
    vector <int> soln = repeating_and_missing_element(nums);
    for(int val : soln){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}