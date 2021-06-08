#include<bits/stdc++.h>

using namespace std;


int partitionFunc(vector<int> &arr,int start,int end){
    int pivot = end;
    int left = start;
    int right = end-1;

    while(left<=right){
        while(left<=end&&arr[left]<arr[pivot]) left++;
        while(right>=start&&arr[right]>=arr[pivot]) right--;

        if(left<right) swap(arr[left],arr[right]);
        else swap(arr[left],arr[pivot]);
    }
    return left;
}
void quickSortSubarray(vector<int> &arr,int start,int end){
if(start>=end) return;
int partition = partitionFunc(arr,start,end);
quickSortSubarray(arr,start,partition-1);
quickSortSubarray(arr,partition+1,end);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";
   
    quickSortSubarray(arr,0,n-1);
    cout<<"\n";
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}