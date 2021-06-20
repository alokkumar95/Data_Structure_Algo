#include<bits/stdc++.h>

using namespace std;

void solve(vector<int> &arr){
stack<int> s;

   int n = arr.size();

   for(int i=n-1;i>=0;i--){
       while(!s.empty()&&s.top()<=arr[i])
       s.pop();

       if(s.size()==0) cout<<"-1 ";
       else cout<<s.top()<<" ";
       s.push(arr[i]);
   }
}
int main(){
    int n;
    cin>>n;
    vector<int> arr={1, 3, 0, 2, 5};
    solve(arr);
}