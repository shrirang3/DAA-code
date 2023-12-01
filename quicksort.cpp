#include<iostream> 
#include<string.h>
#include<limits.h>
#include<vector>
using namespace std;



int partition(int arr[], int s, int e){


    //step 1: select pivot
    int pivotindex=s;
    int pivotelement=arr[s];

    //step 2: find right position of pivot and place it at right position

    int count=0;
    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivotelement){
            count++;
        }
    }

    //putting  pivot to it's correct position
    int pivotcorrectindex=s+count;
    swap(arr[pivotcorrectindex], arr[pivotindex]);
    pivotindex=pivotcorrectindex;  //updating pivot index

    //step 3: left mein small and right mein bade
    int i=s;
    int j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<=pivotelement){
            i++;

        }
        while(arr[j]>pivotelement){
            j--;
        }

        //for invalid cases swapping
        if(i<pivotindex && j>pivotindex){
            swap(arr[i], arr[j]);
        }
    }

   


    return pivotindex;
}


void Quicksort(int arr[], int s, int e){

    //base case
    if(s>=e){
        return;
    }

    //partition logic  return->pivot
    int p=partition(arr, s, e);

    //reccursive calls

    //left
    Quicksort(arr, s, p-1);

    //right
    Quicksort(arr, p+1, e);

}



int main(){

    int arr[]={8, 8, 8, 1, 3, 4, 20, 50, 30, 111, 111, 111};
    int n=12;
    int s=0;
    int e=n-1;
    Quicksort(arr, s, e);

    for(int  i=0; i<n; i++){

        cout<<arr[i]<<" ";
    }
    cout<<endl;



    return 0;
}