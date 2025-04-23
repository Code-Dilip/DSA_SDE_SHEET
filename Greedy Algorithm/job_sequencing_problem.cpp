#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct job{
    int id;
    int deadline;
    int profit;
};

bool comp(struct job val1, struct job val2){
    return (val1.profit > val2.profit);
}

int job_sequencing(struct job jobs[], int n){

    sort(jobs, jobs+n, comp);

    int max_deadline = -1;
    for(int i=0;i<n;i++){
        max_deadline = max(max_deadline, jobs[i].deadline);
    }

    vector hash_arr(max_deadline+1, -1);
    int cnt = 0;
    int total_profit = 0;

    for(int i=0;i<n;i++){
        for(int j=jobs[i].deadline; j>=0; j--){
            if(hash_arr[j]==-1){
                hash_arr[j] = jobs[i].id;
                total_profit += jobs[i].profit;
                cnt += 1;
                break;
            }
        }
    }

    return cnt;
}

int main(){
    
    struct job jobs[] = {{6,2,80}, {3,6,70}, {4,6,65}, {2,5,60}, {5,4,25}, {8,2,22}, {1,4,20}, {7,2,10}};
    int n = 8;

    cout<<job_sequencing(jobs, n)<<endl;
    return 0;
}