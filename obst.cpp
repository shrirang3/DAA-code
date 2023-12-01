#include<iostream> 
#include<string.h>
#include<limits.h>
#include<vector>
using namespace std;

int sum(int freq[], int i, int j){

    int s=0;
    for(int k=i; k<=j; k++){
        s+=freq[k];
    }

    return s;
}

int optimalSearchTree(int freq[], int i, int j){

    //base case
    if(i>j){
        return 0;
    }
    if(i==j){
        return freq[i];
    }

    int mincost=INT_MAX;

    int tsum=sum(freq, i, j);

    for(int k=i; k<=j; k++){
        //try each for root node
        int cost=optimalSearchTree(freq, i, k-1)+optimalSearchTree(freq, k+1, j);

        mincost=min(mincost, cost);
    }

    return mincost+tsum;



}

int main(){

    int keys[] = {10, 12, 20}; 
    int freq[] = {34, 8, 50}; 
    int n = sizeof(keys) / sizeof(keys[0]); 

    cout<<optimalSearchTree(freq, 0, n-1);
    
    return 0; 

}