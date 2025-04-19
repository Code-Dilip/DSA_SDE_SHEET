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

    sort(arr.begin(),arr.end());
    
    vector <vector<int>> ans;

    for(int i=0;i<n;i++){
        if(i>0 && arr[i]==arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(sum == target){
                ans.push_back({arr[i],arr[j],arr[k]});
                j ++;
                k --;
                while(j<k && arr[j]==arr[j-1]){
                    j ++;
                }
                while(j<k && arr[k]==arr[k+1]){
                    k --;
                }
            }
            else if(sum < target){
                j ++;
            }
            else{
                k --;
            }
        }
    }

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