#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    public:
    Node(int data1 ,Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convert(vector<int> &nums){
    Node * head = new Node(nums[0]);
    Node *mover = head;
    for(int i=1; i<nums.size(); i++){
        Node *temp = new Node(nums[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(){
    vector<int> arr = {1 ,2,3,4};
    Node * head = convert(arr);
    Node * temp = head;
    while(temp!= nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}