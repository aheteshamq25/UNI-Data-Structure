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

Node* reverseDll(Node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }
    Node* curr = head;
    Node* temp = nullptr;
    while(curr != nullptr){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;

    }

    return temp->prev;

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
    cout<<"Before reverse: ";
    display(temp);
    cout << endl;

    Node* newNode = reverseDll(temp);
    cout << "After reverse: ";
    display(newNode);
    cout << endl;
    return 0;


}