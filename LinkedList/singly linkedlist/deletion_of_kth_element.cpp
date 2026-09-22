#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int data1, Node*next1){
        data = data1;
        next=next1;
    }
    Node(int data1){
        data = data1;
        next= nullptr;
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

Node* deletionOfKthEle(Node*head, int pos){
    if(head==NULL) return NULL;
    if(head->next == NULL) {
        delete head;
        return NULL;
    }
    if(pos == 1 ){
        Node* temp = head;
        temp = temp->next;
        return temp;
    }
    int cnt=0;

    Node * temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==pos){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

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
    display(temp);
    cout<<endl;
    
    Node * newNode = deletionOfKthEle(temp , 3);
    display(newNode);
    
    return 0;


}