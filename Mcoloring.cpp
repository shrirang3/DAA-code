#include<bits/stdc++.h>
using namespace std;
bool possiable(int node,vector<int>& color,vector<vector<int>>&adjMatrix,int n,int i){
    for(int k=0;k<n;k++){
        if(k!=node && adjMatrix[k][node]==1 && color[k]==i){
            return false;
        }
    }
    return true;
}
bool solve(int node,vector<vector<int>>& adjMatrix,int m,vector<int>&color,int n){
    if(node==n){
        return true;
    }
    for(int i=1;i<=m;i++){
        if(possiable(node,color,adjMatrix,n,i)){
            color[node]=i;
            if(solve(node+1,adjMatrix,m,color,n)){
                return true;
            }
            color[node]=0;
        }
    }
    return false;
}
bool mColoring(vector<vector<int>> adjMatrix,int m){
    int n=adjMatrix.size();
    vector<int> color(n,0);
    if(solve(0,adjMatrix,m,color,n)){
        return true;
    }
    return false;
}
int main(){
    vector<vector<int>> adjMatrix={
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m=3;
    cout<<mColoring(adjMatrix,m);
}