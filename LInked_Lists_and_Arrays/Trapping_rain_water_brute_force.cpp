#include<iostream>
#include<vector>
using namespace std;

vector <int> PrefixMax(vector <int> heights){
    int n = heights.size();
    vector <int> prefixMax(n,0);
    prefixMax[0] = heights[0];

    for(int i=1;i<n;i++){
        prefixMax[i] = max(prefixMax[i-1], heights[i]);
    }

    return prefixMax;
}

vector <int> SuffixMax(vector <int> heights){
    int n = heights.size();
    vector <int> suffixMax(n,0);
    suffixMax[n-1] = heights[n-1];

    for(int i=n-2;i>=0;i--){
        suffixMax[i] = max(suffixMax[i+1],heights[i]);
    }
    return suffixMax;
}


int trapped_rain_water(vector <int> heights){
    int n = heights.size();
    if(n==0) return 0;

    vector <int> prefixMax = PrefixMax(heights);
    vector <int> suffixMax = SuffixMax(heights);

    int trapped_water = 0;

    for(int i=0;i<n;i++){
        trapped_water += min(prefixMax[i], suffixMax[i]) - heights[i];
    }

    return trapped_water;
}

int main(){
    vector <int> heights = {0,1,0,2,1,0,1,3,2,1,2};
    cout<<trapped_rain_water(heights)<<endl;
    return 0;
}