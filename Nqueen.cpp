#include<iostream> 
#include<string.h>
#include<limits.h>
#include<vector>
using namespace std;


void printSolution(vector<vector<int>> &board, int n){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }

        cout<<endl;
    }
    cout<<endl;
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n){


    //checking if queen can be placed in the current cell

    int i=row;
    int j=col;

    // left check
    while(j>=0){
        
        if(board[i][j]==1){
            return false;
        }
        j--;

    }

    i=row;
    j=col;

    // check upper left diagonal
    while(i>=0 && j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--;
        j--;
    }


    i=row;
    j=col;

    //check lower left diagonal
    while(i<n && j>=0){
        if(board[i][j]==1){
            return false;
        }
        i++;
        j--;
    }

    return true;
}


void solve(vector<vector<int>> &board, int col, int n){

    //base case
    if(col>=n){
        printSolution(board, n);
        return;
    }

    //1 case solve karo
    //first queen ko first column mein sab rows pe rakh ke try karo baki reccursion

    for(int row=0; row<n; row++){

        if(isSafe(row, col, board, n)){

            //rakh do
            board[row][col]=1; 

            //reccursive call for next column
            solve(board, col+1, n);

            //backtracking game
            board[row][col]=0;
        }

    }


}

int main(){

    int n=9;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int col=0;
    solve(board, col, n);



    return 0;
}