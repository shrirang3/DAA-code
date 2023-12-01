#include<iostream> 
#include<string.h>
#include<limits.h>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }


};

void traverse(Node* root, vector<string>& ans, string temp) {
    // base case
    if (!root->left && !root->right) {
        ans.push_back(temp);
        return;
    }

    traverse(root->left, ans, temp + '0');
    traverse(root->right, ans, temp + '1');
}

vector<string> huffman(string s, vector<int>&f, int N){

    priority_queue<Node*, vector<Node*>, greater<Node*>> pq;

    for(int i=0; i<N; i++){
        Node* temp=new Node(f[i]);
        pq.push(temp);
    }

    while(pq.size()>1){
        auto left=pq.top();
        pq.pop();
        auto right=pq.top();
        pq.pop();

        Node* newnode=new Node(left->data+right->data);
        newnode->left=left;
        newnode->right=right;
        pq.push(newnode);
    }

    //single element left i.e root node left
    Node* root=pq.top(); 
    vector<string> ans;
    string temp="";
    traverse(root, ans, temp);

    return ans;
}


int main(){

    vector<int>f={5, 9, 12, 13, 16, 45};
    string s="abcdef";

    vector<string> ans=huffman(s, f, 6);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;



    return 0;
}