#include<iostream>
#include<algorithm>
using namespace std;

struct weight_and_value{
    int val;
    int weight;
};

bool comp(struct weight_and_value val1, struct weight_and_value val2){
    if((val1.val/val1.weight) >= (val2.val/val2.weight)){
        return 1;
    }
    return 0;
}

int fractional_ksnap(struct weight_and_value arr[], int n, int w){

    sort(arr, arr+n, comp);

    int total_profit = 0;
    for(int i=0;i<n;i++){
        if(arr[i].weight <= w){
            total_profit += arr[i].val;
            w = w - arr[i].weight;
        }
        else{
            total_profit += (w * (arr[i].val/arr[i].weight));
            break; 
        }
    }

    return total_profit;
}

int main(){
    struct weight_and_value arr[] = {{100,20}, {60,10}, {100,50}, {200,50}};
    int n = 4;
    int w = 90;

    cout<<fractional_ksnap(arr, n, w)<<endl;
    return 0;
}