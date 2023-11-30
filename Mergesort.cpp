#include<iostream> 
#include<string.h>
#include<limits.h>
#include<vector>
using namespace std;


void merge(int *arr, int s, int e){

    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    //creating 2 arrays
    int *left=new int[len1];
    int *right=new int[len2];

    //copy values
    int mainIndex=s;
    for(int i=0; i<len1; i++){
        left[i]=arr[mainIndex++];
       
    }

    mainIndex=mid+1;
    for(int i=0;i<len2; i++){
        right[i]=arr[mainIndex++];
        
    }

    //logic of merge 2 sorted arrays
    int lIndex=0;
    int rIndex=0;
    mainIndex=s;

    while(lIndex<len1 && rIndex<len2){
        if(left[lIndex]<right[rIndex]){
            arr[mainIndex++]=left[lIndex++];
            
        }
        else{
            arr[mainIndex++]=right[rIndex++];
        }
    }

    //copy
    while(lIndex<len1){
        arr[mainIndex++]=left[lIndex++];
    }

    while(rIndex<len2){
        arr[mainIndex++]=right[rIndex++];
    }


}




void mergesort(int *arr, int s, int e){

    //base case
    //s==e->single element
    //s>e->invalid array

    if(s>=e){
        return;
    }

    int mid=(s+e)/2;

    //left part
    mergesort(arr, s, mid);

    //right part
    mergesort(arr, mid+1, e);


    //now merge 2 sorted arrays
    merge(arr, s, e);
}



int main(){

    int arr[]={4, 5, 13, 2, 12, 120, 120, 120, 110, 110, 70};
    int n=11;


    int s=0;
    int e=n-1;
    mergesort(arr, s, e);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;



    return 0;
}