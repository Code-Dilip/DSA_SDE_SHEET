#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge_overlapping_intervals(vector<vector<int>> intervals){
    vector<vector<int>> ans;
    int n = intervals.size();
    sort(intervals.begin(),intervals.end());

    for(int i=0;i<n;i++){
        int start = intervals[i][0];
        int end = intervals[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j=i+1;j<n;j++){
            if(intervals[j][0] <= end){
                end = max(end,intervals[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;
}

int main(){
    vector <vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector <vector<int>> ans = merge_overlapping_intervals(intervals);
    for(vector<int> interval : ans){
        cout<<"{";
        for(int val: interval){
            cout<<val<<" ";
        }
        cout<<"} ";
    }
    cout<<endl;
    return 0;
}