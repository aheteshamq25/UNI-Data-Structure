#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int a;
    Node *next;

    Node(int a1, Node *next1)
    {
        a = a1;
        next = next1;
    }
    Node(int a1)
    {
        a = a1;
        next = nullptr;
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

Node* deleteNode(Node* head){
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next =NULL;
    delete temp->next;

    return head;
    

}

int main(){
    vector<int> arr = {1,3,4,6,7,9};
    Node* head = convertToLinkedList(arr);
    Node * temp = deleteNode(head);

    while (temp != nullptr)
    {
        cout<<temp->a<<" ";
        temp = temp->next;
    }

    return 0;
    
}