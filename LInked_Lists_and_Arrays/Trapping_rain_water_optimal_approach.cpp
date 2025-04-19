#include<iostream>
#include<vector>
using namespace std;



int trapped_rain_water(vector <int> heights){
    int n = heights.size();
    if(n==0) return 0;

    int lMax = 0, rMax = 0, l = 0, r = n-1;
    int trapped_water = 0;

    while(l<r){
        if(heights[l]<=heights[r]){
            if(lMax > heights[l]){
                trapped_water += lMax - heights[l];
            }
            else{
                lMax = heights[l];
            }
            l ++;
        }
        else{
            if(rMax > heights[r]){
                trapped_water += rMax - heights[r];
            }
            else{
                rMax = heights[r];
            }
            r --;
        }
    }
    return trapped_water;
}

int main(){
    vector <int> heights = {0,1,0,2,1,0,1,3,2,1,2};
    cout<<trapped_rain_water(heights)<<endl;
    return 0;
}