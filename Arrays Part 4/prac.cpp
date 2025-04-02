#include<iostream>
#include<string>
#include<map>
using namespace std;

int longest_substring(string str){
    int n = str.length();
    int max_len = 0;

    for(int i=0;i<n;i++){
        int hash_arr[256] = {0};
        int len = 0;
        for(int j=i;j<n;j++){
            if(hash_arr[str[j]]==1){
                break;
            }
            hash_arr[str[j]] = 1;
            len = j-i+1;
            max_len = max(max_len,len);
        }
    }

    return max_len;
}

int main(){
    string str = "pwwkew";
    cout<<longest_substring(str)<<endl;
    return 0;
}