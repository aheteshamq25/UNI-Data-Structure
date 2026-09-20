#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val1 , Node* next1 , Node * prev1){
        val = val1;
        next = next1;
        prev = prev1;
    }
    Node(int val1 ){
        val = val1;
        next = nullptr;
        prev = nullptr;
    }
   
};

Node* convertArrToDll( vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

Node* insertBeforeHead(Node* head , int val){
    Node* temp = head;
    Node* newNode = new Node(val);
    newNode->next = temp;
    temp->prev = newNode;
    temp = newNode;
    return newNode;
}

void display(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp= temp->next;
    }
}

int main(){
    vector<int> arr = {3,4,5,7,8,9};
    Node * head = convertArrToDll(arr);
    Node * temp = head;
    
    int val ;
    cout<<"Enter the value for Node: ";
    cin>>val;
    

    cout<<"Before NEw NOde: ";
    display(temp);
    cout<<"\nAfter newNode at begin: ";
    Node * newNode = insertBeforeHead(temp , val);
    display(newNode);
     
}