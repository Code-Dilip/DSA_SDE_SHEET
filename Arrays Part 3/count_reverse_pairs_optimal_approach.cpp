#include<iostream>
#include<vector>
using namespace std;

void merge(vector <int> &nums,int low,int mid,int high){
    vector <int> temp;
    int left = low;
    int right = mid+1;
    
    while (left<=mid && right<=high)
    {
        if(nums[left]<=nums[right]){
            temp.push_back(nums[left]);
            left ++;
        }
        else{
            temp.push_back(nums[right]);
            right ++;
        }
    }
    while(left<=mid){
        temp.push_back(nums[left]);
        left ++;
    }
    while(right<=high){
        temp.push_back(nums[right]);
        right ++;
    }
    
    for(int i=low;i<=high;i++){
        nums[i] = temp[i-low];
    }

}

int count_reverse_pairs(vector <int> nums, int low,int mid,int high){
    int cnt = 0;
    int right = mid+1;

    for(int left=low;left<=mid;left++){
        while(right<=high && nums[left]>2*nums[right]){
            right ++;
        }
        cnt += (right-(mid+1));
    }
    return cnt;
}

int mergeSort(vector<int> &nums, int low,int high){
    if(low<high){
        int cnt = 0;
        int mid = (low+high)/2;

        cnt += mergeSort(nums,low,mid);
        cnt += mergeSort(nums,mid+1,high);
        cnt += count_reverse_pairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
    }
    return 0;
}

int main(){
    vector <int> nums = {40,25,19,12,9,6,2};
    cout<<mergeSort(nums,0,nums.size()-1)<<endl;
    for(int val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}