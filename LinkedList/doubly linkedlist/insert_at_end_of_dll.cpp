#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;

    Node(int data1, Node*next1, Node*prev1){
        data = data1;
        next=next1;
        prev= prev1;
    }
    Node(int data1){
        data = data1;
        next= nullptr;
        prev= nullptr;
    }
};

Node* convertArrToDll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node * mover = head;
    for(int i= 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* insertAtEnd(Node* head , int k){
    Node* newNode = new Node(k);
    if(head == nullptr){
        return newNode;
    }
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->prev = tail;

    return head;

}

Node* insertAtBegin(Node* head , int k){
    Node* newNode = new Node(k);
    if(head == nullptr){
        return newNode;
    }

    Node* temp= head;
    temp->prev = newNode;
    newNode->next = temp;

    return newNode;
}

void display(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}


int main(){
    vector<int> arr = {12, 3, 5, 6, 7};
    Node * head = new Node(arr[0]);
    Node* temp = convertArrToDll(arr);
    cout<<"BEFORE INSERT NEW NODE"<<endl;
    display(temp);

    Node* newTemp = insertAtEnd(temp , 10);
    cout<<"\nAFTER INSERT NEW NODE"<<endl;
    display(newTemp);
    Node* newtemp2 = insertAtBegin(temp , 1);
    cout<<"\nINSERT NEW NODE AT BEGIN: "<<endl;
    display(newtemp2);

    return 0;


}