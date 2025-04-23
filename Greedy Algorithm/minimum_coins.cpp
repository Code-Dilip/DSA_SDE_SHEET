#include<iostream>
#include<vector>
using namespace std;

void minimum_coins(vector <int> denominations, int val){
    vector <int> ans;
    int n = denominations.size();

    for(int i=n-1;i>=0;i--){
        while(val >= denominations[i]){
            val -= denominations[i];
            ans.push_back(denominations[i]);
        }
    }

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector <int> denominations = {1,2,5,10,20,50,100,500,1000};
    int val = 87;
    minimum_coins(denominations, val);
    return 0;
}