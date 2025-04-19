#include<iostream>
#include<set>
#include<vector>
using namespace std;

void remove_duplicates(vector <int> &sort_arr){
    int n = sort_arr.size();
    if(n==0) return ;

    set <int> st;
    for(int i=0;i<n;i++){
        st.insert(sort_arr[i]);
    }

    int i=0;
    for(auto ele : st){
        sort_arr[i] = ele;
        i ++;
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