#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longest_substring(string str){
    int n = str.length();
    int max_length = 0;

    for(int i=0;i<n;i++){
        int hash_arr[256] = {0};
        for(int j=i;j<n;j++){
            if(hash_arr[str[j]]==1){
                break;
            }
            hash_arr[str[j]] = 1;
            max_length = max(max_length, j-i+1);
        }
    }
    return max_length;
}

int main(){
    string str = "pwwkew";
    cout<<longest_substring(str)<<endl;
    return 0;
}