#include<bits/stdc++.h>

using namespace std;

void printAllBinary(vector<vector<int>> &pars,vector<int> &par,int k){
  if(k==par.size()){
    pars.push_back(par);
    return;
  }
  else{
      for(int i=0;i<2;i++){
            par.push_back(i);
            printAllBinary(pars,par,k);
            par.pop_back();
      }
  }
}

int main(){
    int k;
    cin>>k;

    vector<int> par;
    vector<vector<int>> pars;

    printAllBinary(pars,par,k);
    cout<<pars.size()<<"\n";
    for(int i=0;i<pars.size();i++){
        for(int j=0;j<pars[i].size();j++){
            cout<<pars[i][j]<<" ";
        }
        cout<<"\n";
    }
}