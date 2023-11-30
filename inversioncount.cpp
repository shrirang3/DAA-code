#include<iostream> 
#include<string.h>
#include<limits.h>
#include<vector>
using namespace std;

int count=0;

void merge(int arr[], int s, int m, int e){

    int low=s;
    int high=m+1;
    vector<int>temp;

    while(low<=m && high<=e){

        if(arr[low]<=arr[high]){
            //no swap condition
            temp.push_back(arr[low]);
            low++;
        }
        else{
            //swap found
            count+=(m-low+1);
            temp.push_back(arr[high]);
            high++;
        }
    }

    while(low<=m){
        //no swap condition
        temp.push_back(arr[low]);
        low++;
    }

    while(high<=e){
        temp.push_back(arr[high]);
        high++;
    }

    for(int i=s; i<=e; i++){
        arr[i]=temp[i-s];
    }
}

void mergesort(int arr[], int s, int e){

    if(s>=e){
        return;
    }

    int m=s+(e-s)/2;
    mergesort(arr, s, m);
    mergesort(arr, m+1, e);

    merge(arr, s, m, e);

}

int main(){

    int arr[]={1, 9, 6, 4, 5};
    int n=5;
    mergesort(arr, 0, 4);
    cout<<count;



    return 0;
}