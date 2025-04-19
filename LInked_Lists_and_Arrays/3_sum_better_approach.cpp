#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

vector <vector<int>> find_unique_triplets(vector <int> arr, int target){
    int n = arr.size();
    if(n==0){
        return {};
    }
    
    set <vector<int>> st;
    
    for(int i=0;i<n;i++){
        set <int> hash_set;
        for(int j=i+1;j<n;j++){
            int more = target - (arr[i]+arr[j]);
            if(hash_set.find(more) != hash_set.end()){
                vector <int> temp = {arr[i],arr[j],more};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash_set.insert(arr[j]);
        }
    }

    vector <vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main(){

    vector <int> arr = {-1,0,1,2,-1,-4};
    int target = 0;

    vector<vector<int>> unique_triplets = find_unique_triplets(arr, target);

    for(vector <int> unique_triplet : unique_triplets){
        cout<<"{";
        for(int ele : unique_triplet){
            cout<<ele<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;

    return 0;
}