#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longest_substring(string str){
    int n = str.length();
    vector <int> hash_map(256,-1);
    int max_length = 0;
    int left = 0;
    int right = 0;

    while(right < n){
        if(hash_map[str[right]!=-1]){
            if(left <= hash_map[str[right]]){
                left = hash_map[str[right]]+1;
            }
        }
        int len = right - left+1 ;
        max_length = max(max_length, len);
        hash_map[str[right]] = right;
        right ++;
    }

    return max_length;
}

int main(){
    string str = "abcabcbb";
    cout<<longest_substring(str)<<endl;
    return 0;
}