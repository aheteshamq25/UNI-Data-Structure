#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val1 ,Node* next1,
    Node* prev1 ){
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

Node* convertArrToDll(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1 ; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

Node* insertBeforeTail(Node* head , int k){
    Node * temp = head;
    while(temp->next->next !=nullptr){
        temp = temp->next;
    }
    Node* tail = temp->next;
    Node* newNode = new Node(k);
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = tail;
    tail->prev = newNode;

    return head;
}
void display(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp= temp->next;
    }
}

int main(){
    vector<int> arr = {1,3,4,6,5,7,8};

    Node* temp = convertArrToDll(arr);
    display(temp);
    cout<<endl;

    Node * temp2 = insertBeforeTail(temp , 40);
    display(temp2);
    return 0;
}