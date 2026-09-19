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
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

Node* deleteEndNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    while (temp->next != nullptr){
        temp = temp->next;

    }
    temp->prev->next = nullptr;
    delete temp;

    return head;
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
    Node* temp = convertArrToDll(arr);
    cout<<"BEFORE INSERT NEW NODE"<<endl;
    display(temp);

    Node* newhead = deleteEndNode(temp);

    cout<<"AFTER DELETING NODE"<<endl;
    display(newhead);
    
    return 0;


}