#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next =nullptr;
    }
};

Node * convertToLinkedList(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node * mover = head;
    for(int i=1; i<arr.size(); i++){
        Node*temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

}

int searchLl(Node* head , int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val){
            return 1;
        }
        temp = temp->next;

    }
    return 0;

}

int main(){
    vector<int> arr = {1,23,4,6,8,9};
    Node * head = convertToLinkedList(arr);
    cout<<searchLl(head , 2);
    
    return 0;
}