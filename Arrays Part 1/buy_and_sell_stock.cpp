#include<iostream>
#include<vector>
using namespace std;

int buy_and_sell_stock(vector <int> prices){
    int n = prices.size();
    int max_profit = 0;
    int profit = 0;
    int mini_price = prices[0];
    for(int i=1;i<n;i++){
        mini_price = min(prices[i], mini_price);
        profit = prices[i] - mini_price;
        max_profit = max(profit, max_profit);
    }
    return max_profit;
}

int main(){
    vector <int> prices = {7,6,4,3,1};
    cout<<buy_and_sell_stock(prices)<<endl;
    return 0;
}