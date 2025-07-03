#include<iostream>
#include<vector>
using namespace std;

string kth_permutation_sequence(int n, int k){
    vector <int> nums;
    int fact = 1;
    for(int i=1;i<n;i++){
        nums.push_back(i);
        fact = fact*i;
    }
    nums.push_back(n);
    k = k-1;
    string ans = "";
    while(true){
        ans = ans + to_string(nums[k/fact]);
        nums.erase(nums.begin()+k/fact);
        if(nums.size()==0){
            break;
        }
        k = k%fact;
        fact = fact/nums.size();
    }
    return ans;
}

int main(){
    int n = 4;
    int k = 17;
    
    string ans = kth_permutation_sequence(n, k);
    cout<<ans<<endl;
    return 0;
}