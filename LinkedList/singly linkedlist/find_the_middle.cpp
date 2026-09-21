#include<iostream>

using namespace std;

struct Node{
    int val;
    Node* next;

    Node(int a1 , Node* next1){
        val = a1;
        next = next1;
    }
    Node(int a1){
        val= a1;
        next = nullptr;
    }
    Node(){
        next = nullptr;
    }
};

class Solution{
    public:
    Node* middleNode(Node * head){
        Node * temp = head;
        int cnt = 0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        cnt = cnt/2;
        
        Node* newHead = head; 
        for(int i=0; i<cnt; i++){
            newHead = newHead->next;
        }

        return newHead;
    }
};

int main(){


}