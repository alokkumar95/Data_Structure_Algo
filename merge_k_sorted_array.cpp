#include<bits/stdc++.h>

using namespace std;

typedef pair<int,pair<int,int>> pii;



int main(){
    int k;
    cin>>k;

    vector<vector<int>> arr(k);

    for(int i=0;i<k;i++){
        int size;
        cin>>size;
        vector<int> nums(size);
        for(int j=0;j<size;j++){
            cin>>nums[j];
        }
        arr[i]=nums;
    }
   priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<k;i++){
        pq.push({arr[i][0],{i,0}});
    }
    vector<int> ans;
    while(!pq.empty()){
        pii top=pq.top();
        pq.pop();

        ans.push_back(top.first);
        int i=top.second.first;
        int j =top.second.second;

        if(j+1<arr[i].size()) pq.push({arr[i][j+1],{i,j+1}});
    }

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";

}