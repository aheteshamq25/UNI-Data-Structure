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

Node* insertBeforeKthPosition(Node* head , int val , int pos, vector<int> &arr){
    Node* temp = head;
    if(pos > arr.size()){
        cout<<"\nPosition Exceeded!!!"<<endl;
        cout<<"Try again !!!"<<endl;
        return NULL;

    }
    else if(pos ==1){
        Node* newNode  = new Node(val);
        temp->prev = newNode;
        newNode->next = temp;
        return newNode;
    }else{
            
        for(int i =1; i<pos-1; i++){
            temp = temp->next;
        }
        Node* newTemp = temp->next;
        Node* newNode = new Node(val);
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = newTemp;
        newTemp->prev = newNode;
    }
    
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
    int val , pos;
    vector<int> arr = {1,3,4,6,5,7,8};

    cout<<"Enter the value: ";
    cin>>val;
    cout<<"Enter the Position: ";
    cin>>pos;

    cout<<"Before Insertion of Node: ";

    Node* temp = convertArrToDll(arr);
    display(temp);
    cout<<endl;
    cout<<"After Insertion of Node: ";
    Node* temp1 = insertBeforeKthPosition(temp , val , pos, arr);
    display(temp1);
    

    return 0;
}