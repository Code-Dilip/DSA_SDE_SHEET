#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longest_consequetive_sequence(vector <int> arr){
    int n = arr.size();
    int max_length = 1;
    int cnt = 1;
    unordered_set <int> st;

    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }

    for(auto it : st){
        if(st.find(it-1)==st.end()){
            cnt = 1;
            while(st.find(it+1)!=st.end()){
                cnt ++;
                it ++;
            }
            max_length = max(max_length,cnt);
        }
    }
    return max_length;
}

int main(){
    vector <int> arr = {0,3,7,2,5,8,4,6,0,1};
    cout<<longest_consequetive_sequence(arr)<<endl;
    return 0;
}