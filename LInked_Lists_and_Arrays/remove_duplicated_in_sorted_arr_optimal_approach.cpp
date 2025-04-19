#include<iostream>
#include<set>
#include<vector>
using namespace std;

void remove_duplicates(vector <int> &sort_arr){
    int n = sort_arr.size();
    if(n==0) return ;

    int i = 0;
    for(int j = i+1;j<n;j++){
        if(sort_arr[j]!=sort_arr[i]){
            sort_arr[i+1] = sort_arr[j];
            i ++;
        }
    }
}

int main(){
    vector <int> sort_arr = {1,1,2,2,2,3,3};
    remove_duplicates(sort_arr);
    
    for(int ele : sort_arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}