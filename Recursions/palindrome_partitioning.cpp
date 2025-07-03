#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start<=end){
        if(s[start]!=s[end]) return false;
        start ++;
        end --;
    }
    return true;
}

void helper_func(string s, int idx, vector <string> &path, vector <vector<string>> &ans){
    if(idx==s.size()){
        ans.push_back(path);
        return ;
    }
    for(int i=idx;i<s.size();i++){
        if(isPalindrome(s, idx, i)){
            path.push_back(s.substr(idx, i-idx+1));
            helper_func(s, i+1, path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> get_palindrome_substrings(string s){
    if(s.size()==0) return {{}};
    vector <vector<string>> ans;
    vector <string> path;
    helper_func(s, 0, path, ans);
    return ans;
}

int main(){

    string s = "aabb";
    vector<vector<string>> res;
    res = get_palindrome_substrings(s);

    for(vector<string> str : res){
        cout<<"[";
        for(auto it : str){
            cout<<it<<" ";
        }
        cout<<"] ";
    }
    cout<<endl;
    return 0;
}   