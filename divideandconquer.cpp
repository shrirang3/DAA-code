#include<iostream> 
#include<string.h>
#include<limits.h>
#include<vector>
using namespace std;


int first(int nums[], int n){

    int s=0;
    int e=n-1;
    int ans=-1;


    while(s<=e){
        int m=s+(e-s)/2;

        if(nums[m]==1){
            ans=m;
            e=m-1;
        }
        else if(nums[m]<1){
            s=m+1;
        }
        
    }

    return ans;
}

// int main(){

//     int nums[]={0, 0, 0, 0, 1, 1, 1};
//     int n=7;

    

//     int firstocc=first(nums, n);
//     cout<<firstocc<<endl;
//     cout<<n-firstocc<<endl;



//     return 0;
// }


int firstmissing(int nums[], int s, int e){

    while(s<=e){

        if(s!=nums[s]){
            return s;
        }

        int m=s+(e-s)/2;

        if(nums[m]==m){
            s=m+1;
        }
        else{
            e=m;
        }
    }

    return e+1;
}

// int main(){

//     int nums[]={0, 1, 2, 6, 9, 11, 15};

//     cout<<firstmissing(nums, 0, 6);

//     return 0;
// }

// int kdiffpair(vector<int>&nums, int k){

// }

// int main(){

//     vector<int>nums={1, 5, 2, 2, 2, 5, 5, 4};
//     int k=3;

//     return 0;
// }

int firstocc(vector<int>&nums, int k){

    int s=0;
    int e=nums.size()-1;
    int ans=-1;

    while(s<=e){
        int m=s+(e-s)/2;

        if(nums[m]==k){
            ans=m;
            e=m-1;
        }
        else if(nums[m]<k){
            s=m+1;
        }
        else{
            e=m-1;
        }
    }

    return ans;

}

int lastocc(vector<int>&nums, int k){

    int s=0;
    int e=nums.size()-1;
    int ans=-1;

    while(s<=e){
        int m=s+(e-s)/2;

        if(nums[m]==k){
            ans=m;
            s=m+1;
        }
        else if(nums[m]<k){
            s=m+1;
        }
        else{
            e=m-1;
        }
    }

    return ans;
}

// int main(){

//     vector<int>nums={2, 2, 2, 4, 4, 4, 5, 5, 6, 8, 8, 9};
//     int a=firstocc(nums, 5);
//     int b=lastocc(nums, 5);

//     cout<<a<<endl;
//     cout<<b<<endl;

//     cout<<"Total occ: "<<b-a+1;


//     return 0;
// }

int maxsubarraysum(vector<int>&nums, int n){

    int sum=0;
    int maxi=INT_MIN;

    for(int i=0; i<n; i++){

        sum+=nums[i];
        maxi=max(sum, maxi);


        if(sum<0){
            sum=0;
        }
    }

    return maxi;
}

// int main(){

//     vector<int>nums={2, -4, 1, 9, -6, 7, -3};

//     cout<<maxsubarraysum(nums, 7);

//     return 0;
// }

string commstr(string str1, string str2){

    int n1=str1.size();
    int n2=str2.size();
    string res;
    int i=0;
    int j=0;

    while(i<n1 && j<n2){

        if(str1[i]==str2[j]){
            res.push_back(str1[i]);
            i++;
            j++;
        }
        else{
            break;
        }
    }

    return res;
}

string lcp(string arr[], int low, int high){

    //base case
    if(low==high){
        return arr[low];
    }

    if(high>low){

        int m=low+(high-low)/2;

        string str1=lcp(arr, low, m);
        string str2=lcp(arr, m+1, high);

        return commstr(str1, str2);
    }

}

// int main(){

//     string arr[]={"geeksforgeeks", "geeks",
//                     "geek", "geezer"};
    
//     int n=sizeof(arr)/sizeof(arr[0]);  //gives the number of elements in string array

//     string ans=lcp(arr, 0, n-1);

//     cout<<ans;


//     return 0;
// }

void greedycoloring(vector<vector<int>>&graph, int m){

    int v=graph.size(); //vertices=graph size
    vector<int> color(v, 0);
}


int main(){

    //adjacencymatrix
    vector<vector<int>> graph={{0, 1, 1},
                                {1, 0, 1},
                                {1, 1, 0}};

    
    int m=3;
    greedycoloring(graph, m);

    return 0;
}