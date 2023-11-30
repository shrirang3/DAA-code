#include<iostream> 
#include<string.h>
#include<limits.h>
#include<vector>

using namespace std;

//index here is index of last element
int solveRec(int weight[], int value[], int index, int capacity){

    //base case : only one item
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }

    
    //include
    int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + solveRec(weight, value, index - 1, capacity - weight[index]);
    }

    //exclude
    int exclude=0+solveRec(weight, value, index-1, capacity);

   

    int ans=max(include, exclude);

    return ans;
    
}


//index here is index of last element
int solveMem(int weight[], int value[], int index, int capacity, vector<vector<int>>&dp){

    //base case : only one item
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }


    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }
    
    //include
    int include = 0;
    if (weight[index] <= capacity) {
        include = value[index] + solveMem(weight, value, index - 1, capacity - weight[index], dp);
    }

    //exclude
    int exclude=0+solveMem(weight, value, index-1, capacity, dp);

   

    dp[index][capacity]=max(include, exclude);

    return dp[index][capacity];
    
}

int solveTab(int weight[], int value[], int capacity, int n){

    vector<vector<int>>dp(n, vector<int>(capacity+1, 0));

    for(int w=0; w<=capacity; w++){
        if(weight[0]<=capacity){
            dp[0][w]=value[0];
        }
        else{
            dp[0][w]=0;
        }
    }

    for(int index=1; index<n; index++){
        for(int wt=0; wt<=capacity; wt++){
            //include
            int include = 0;
            if (weight[index] <= wt) {
                include = value[index] +  dp[index - 1][wt - weight[index]];
            }
 
            //exclude
            int exclude=0+dp[index-1][wt];

        

            dp[index][wt]=max(include, exclude);

            
        }
    }

    return dp[n-1][capacity];
}

int main(){

    int weight[]={4, 5, 1};
    int value[]={1, 2, 3};
    int n=3;
    int capacity=4;

    

    

    vector<vector<int>>dp(n, vector<int>(capacity+1, -1));

    int ans=solveTab(weight, value, n-1, capacity);
    cout<<ans<<endl;
    

    return 0;
}